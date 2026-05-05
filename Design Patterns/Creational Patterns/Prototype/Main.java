interface Cloneable {
    Cloneable clone();
}

class Circle implements Cloneable {
    private String color;
    private double radius;

    public Circle(String color, double radius) {
        this.color = color;
        this.radius = radius;
    }

    public Cloneable clone() {
        // TODO: Implement clone()
        return new Circle(this.color, this.radius);
    }

    public void setRadius(double radius) { this.radius = radius; }

    public void printInfo() {
        System.out.println("Circle [Color: " + color + ", Radius: " + radius + "]");
    }
}

class Rectangle implements Cloneable {
    private String color;
    private double width;
    private double height;

    public Rectangle(String color, double width, double height) {
        this.color = color;
        this.width = width;
        this.height = height;
    }

    public Cloneable clone() {
        // TODO: Implement clone()
        return new Rectangle(this.color, this.width, this.height);
    }

    public void setWidth(double width) { this.width = width; }

    public void printInfo() {
        System.out.println("Rectangle [Color: " + color +
                ", Width: " + width + ", Height: " + height + "]");
    }
}

public class Main {
    public static void main(String[] args) {
        // After implementing:
        Circle original = new Circle("Red", 5.0);
        Circle cloned = (Circle) original.clone();
        cloned.setRadius(10.0);
        original.printInfo();  // Circle [Color: Red, Radius: 5.0]
        cloned.printInfo();    // Circle [Color: Red, Radius: 10.0]
        
        Rectangle rect = new Rectangle("Blue", 4.0, 6.0);
        Rectangle clonedRect = (Rectangle) rect.clone();
        clonedRect.setWidth(8.0);
        rect.printInfo();       // Rectangle [Color: Blue, Width: 4.0, Height: 6.0]
        clonedRect.printInfo(); // Rectangle [Color: Blue, Width: 8.0, Height: 6.0]
    }
}