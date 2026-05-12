interface Shape {
    area(): number;
    describe(): void;
}

class Circle implements Shape {
    private radius: number;

    constructor(radius: number) {
        this.radius = radius;
    }

    area(): number {
        return Math.PI * this.radius * this.radius;
    }

    describe(): void {
        console.log(`Circle with area: ${this.area().toFixed(2)}`);
    }
}

class Rectangle implements Shape {
    private width: number;
    private height: number;

    constructor(width: number, height: number) {
        this.width = width;
        this.height = height;
    }

    area(): number {
        return this.width * this.height;
    }

    describe(): void {
        console.log(`Rectangle with area: ${this.area().toFixed(2)}`);
    }
}

class Triangle implements Shape {
    private base: number;
    private height: number;

    constructor(base: number, height: number) {
        this.base = base;
        this.height = height;
    }

    area(): number {
        return 0.5 * this.base * this.height;
    }

    describe(): void {
        console.log(`Triangle with area: ${this.area().toFixed(2)}`);
    }
}

abstract class ShapeCreator {
    abstract createShape(): Shape;

    describe(): void {
        const shape = this.createShape();
        shape.describe();
    }
}

class CircleCreator extends ShapeCreator {
    createShape(): Shape {
        return new Circle(5);
    }
}

class RectangleCreator extends ShapeCreator {
    createShape(): Shape {
        return new Rectangle(4, 6);
    }
}

class TriangleCreator extends ShapeCreator {
    createShape(): Shape {
        return new Triangle(3, 4);
    }
}

// Usage
const circleCreator = new CircleCreator();
circleCreator.describe();

const rectangleCreator = new RectangleCreator();
rectangleCreator.describe();

const triangleCreator = new TriangleCreator();
triangleCreator.describe();
