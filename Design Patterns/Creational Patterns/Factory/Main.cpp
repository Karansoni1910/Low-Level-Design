#include <iostream>
#include <memory>
#include <iomanip>
using namespace std;

// Factory Pattern

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual void describe() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void describe() const override {
        cout << fixed << setprecision(2) << "Circle with area: " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() const override {
        return width * height;
    }

    void describe() const override {
        cout << fixed << setprecision(2) << "Rectangle with area: " << area() << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double base, double height) : base(base), height(height) {}

    double area() const override {
        return 0.5 * base * height;
    }

    void describe() const override {
        cout << fixed << setprecision(2) << "Triangle with area: " << area() << endl;
    }
};

class ShapeCreator {
public:
    virtual ~ShapeCreator() = default;
    virtual shared_ptr<Shape> createShape() = 0;

    void describe() {
        auto shape = createShape();
        shape->describe();
    }
};

class CircleCreator : public ShapeCreator {
public:
    shared_ptr<Shape> createShape() override {
        return make_shared<Circle>(5);
    }
};

class RectangleCreator : public ShapeCreator {
public:
    shared_ptr<Shape> createShape() override {
        return make_shared<Rectangle>(4, 6);
    }
};

class TriangleCreator : public ShapeCreator {
public:
    shared_ptr<Shape> createShape() override {
        return make_shared<Triangle>(3, 4);
    }
};

int main() {
    CircleCreator circleCreator;
    RectangleCreator rectCreator;
    TriangleCreator triCreator;

    cout << "Creating shapes using Factory Pattern:" << endl;
    circleCreator.describe();
    rectCreator.describe();
    triCreator.describe();

    return 0;
}
