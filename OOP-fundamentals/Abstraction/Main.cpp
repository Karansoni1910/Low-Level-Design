#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(const string& name) : name(name) {}
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    void describe() const {
        cout << "Shape: " << name << ", Area: " << fixed << setprecision(2) 
             << area() << ", Perimeter: " << perimeter() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : Shape("Circle"), radius(radius) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height)
        : Shape("Rectangle"), width(width), height(height) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};

int main() {
    Circle circle(5);
    Rectangle rect(4, 6);

    cout << "=== Shapes ===" << endl;
    circle.describe();
    rect.describe();

    return 0;
}
