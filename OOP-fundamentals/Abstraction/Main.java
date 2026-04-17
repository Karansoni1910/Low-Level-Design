abstract class Shape {
    protected String name;

    public Shape(String name) {
        this.name = name;
    }

    abstract double area();
    abstract double perimeter();

    void describe() {
        // Print: "Shape: [name], Area: [area], Perimeter: [perimeter]"
        // Use String.format("%.2f", value) to format to 2 decimal places
        System.out.println("Shape: " + this.name + ", Area: " + String.format("%.2f", area()) + ", Perimeter: " + String.format("%.2f", perimeter()));
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        super("Circle");
        this.radius = radius;
    }

    @Override
    double area() {
        // Area = pi * r^2
        return Math.PI * radius * radius;
    }

    @Override
    double perimeter() {
        // Perimeter = 2 * pi * r
        return 2 * Math.PI * radius;
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        super("Rectangle");
        this.width = width;
        this.height = height;
    }

    @Override
    double area() {
        // Area = width * height
        return width * height;
    }

    @Override
    double perimeter() {
        // Perimeter = 2 * (width + height)
        return 2 * (width + height);
    }
}

public class Main {
    public static void main(String[] args) {
        Shape circle = new Circle(5.0);
        circle.describe();

        Shape rectangle = new Rectangle(4.0, 6.0);
        rectangle.describe();
    }
}