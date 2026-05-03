interface Shape {
    double area();
    void describe();
}

class Circle implements Shape {
    // TODO: Add a private field for radius (double)
    private double radius;

    public Circle(double radius) {
        // TODO: Store the radius
        this.radius = radius;
    }

    @Override
    public double area() {
        // TODO: Return pi * radius * radius (use Math.PI)
        return Math.PI * radius * radius;
    }

    @Override
    public void describe() {
        // TODO: Print "Circle with area: " followed by area() formatted to 2 decimal places
        System.out.printf("Circle with area: %.2f%n", area());
    }
}

class Rectangle implements Shape {
    // TODO: Add private fields for width and height (double)
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        // TODO: Store width and height
        this.width = width;
        this.height = height;
    }

    @Override
    public double area() {
        // TODO: Return width * height
        return width * height;
    }

    @Override
    public void describe() {
        // TODO: Print "Rectangle with area: " followed by area() formatted to 2 decimal places
        System.out.printf("Rectangle with area: %.2f%n", area());
    }
}

class Triangle implements Shape {
    // TODO: Add private fields for base and height (double)
    private double base;
    private double height;

    public Triangle(double base, double height) {
        // TODO: Store base and height
        this.base = base;
        this.height = height;
    }

    @Override
    public double area() {
        // TODO: Return 0.5 * base * height
        return 0.5 * base * height;
    }

    @Override
    public void describe() {
        // TODO: Print "Triangle with area: " followed by area() formatted to 2 decimal places
        System.out.printf("Triangle with area: %.2f%n", area());
    }
}

abstract class ShapeCreator {
    // Factory method - subclasses decide which Shape to create
    public abstract Shape createShape();

    public void describe() {
        // TODO: Call createShape() to get a Shape instance
        // TODO: Call describe() on the shape
        Shape shape = createShape();
        shape.describe();
    }
}

class CircleCreator extends ShapeCreator {
    @Override
    public Shape createShape() {
        // TODO: Return a new Circle with radius 5
        return new Circle(5);
    }
}

class RectangleCreator extends ShapeCreator {
    @Override
    public Shape createShape() {
        // TODO: Return a new Rectangle with width 4 and height 6
        return new Rectangle(4, 6);
    }
}

class TriangleCreator extends ShapeCreator {
    @Override
    public Shape createShape() {
        // TODO: Return a new Triangle with base 3 and height 8
        return new Triangle(3, 8);
    }
}

public class Main {
    public static void main(String[] args) {
        ShapeCreator creator;
        
        creator = new CircleCreator();
        creator.describe();
        
        creator = new RectangleCreator();
        creator.describe();
        
        creator = new TriangleCreator();
        creator.describe();
    }
}