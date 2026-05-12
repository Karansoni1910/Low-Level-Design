interface Cloneable<T> {
    clone(): T;
}

class Circle implements Cloneable<Circle> {
    private color: string;
    private radius: number;

    constructor(color: string, radius: number) {
        this.color = color;
        this.radius = radius;
    }

    clone(): Circle {
        return new Circle(this.color, this.radius);
    }

    setRadius(radius: number): void {
        this.radius = radius;
    }

    printInfo(): void {
        console.log(`Circle [Color: ${this.color}, Radius: ${this.radius}]`);
    }
}

class Rectangle implements Cloneable<Rectangle> {
    private color: string;
    private width: number;
    private height: number;

    constructor(color: string, width: number, height: number) {
        this.color = color;
        this.width = width;
        this.height = height;
    }

    clone(): Rectangle {
        return new Rectangle(this.color, this.width, this.height);
    }

    setWidth(width: number): void {
        this.width = width;
    }

    printInfo(): void {
        console.log(`Rectangle [Color: ${this.color}, Width: ${this.width}, Height: ${this.height}]`);
    }
}

// Usage
const original = new Circle("Red", 5.0);
const cloned = original.clone();
cloned.setRadius(10.0);
original.printInfo();  // Circle [Color: Red, Radius: 5.0]
cloned.printInfo();    // Circle [Color: Red, Radius: 10.0]

const rect = new Rectangle("Blue", 4.0, 6.0);
const clonedRect = rect.clone();
clonedRect.setWidth(8.0);
rect.printInfo();       // Rectangle [Color: Blue, Width: 4.0, Height: 6.0]
clonedRect.printInfo(); // Rectangle [Color: Blue, Width: 8.0, Height: 6.0]
