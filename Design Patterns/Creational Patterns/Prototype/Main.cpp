#include <iostream>
#include <memory>
using namespace std;

// Prototype Pattern

class Cloneable {
public:
    virtual ~Cloneable() = default;
    virtual unique_ptr<Cloneable> clone() const = 0;
};

class Circle : public Cloneable {
private:
    string color;
    double radius;

public:
    Circle(const string& color, double radius) : color(color), radius(radius) {}

    unique_ptr<Cloneable> clone() const override {
        return make_unique<Circle>(*this);
    }

    void setRadius(double r) {
        radius = r;
    }

    void printInfo() const {
        cout << "Circle [Color: " << color << ", Radius: " << radius << "]" << endl;
    }
};

class Rectangle : public Cloneable {
private:
    string color;
    double width;
    double height;

public:
    Rectangle(const string& color, double width, double height)
        : color(color), width(width), height(height) {}

    unique_ptr<Cloneable> clone() const override {
        return make_unique<Rectangle>(*this);
    }

    void setWidth(double w) {
        width = w;
    }

    void printInfo() const {
        cout << "Rectangle [Color: " << color << ", Width: " << width
             << ", Height: " << height << "]" << endl;
    }
};

int main() {
    Circle original("Red", 5.0);
    auto cloned = original.clone();
    Circle* clonedCircle = dynamic_cast<Circle*>(cloned.get());

    if (clonedCircle) {
        clonedCircle->setRadius(10.0);
    }

    original.printInfo();  // Circle [Color: Red, Radius: 5.0]
    if (clonedCircle) {
        clonedCircle->printInfo();  // Circle [Color: Red, Radius: 10.0]
    }

    cout << endl;

    Rectangle rect("Blue", 4.0, 6.0);
    auto clonedRect = rect.clone();
    Rectangle* clonedRectPtr = dynamic_cast<Rectangle*>(clonedRect.get());

    if (clonedRectPtr) {
        clonedRectPtr->setWidth(8.0);
    }

    rect.printInfo();  // Rectangle [Color: Blue, Width: 4.0, Height: 6.0]
    if (clonedRectPtr) {
        clonedRectPtr->printInfo();  // Rectangle [Color: Blue, Width: 8.0, Height: 6.0]
    }

    return 0;
}
