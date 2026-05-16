#include <iostream>
using namespace std;

// Liskov Substitution Principle: Subtypes must be substitutable for their base types

class Bird {
public:
    virtual ~Bird() = default;
    virtual void eat() = 0;
};

class FlyingBird : public Bird {
public:
    virtual ~FlyingBird() = default;
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void eat() override {
        cout << "Sparrow is eating" << endl;
    }

    void fly() override {
        cout << "Sparrow is flying" << endl;
    }
};

class Penguin : public Bird {
public:
    void eat() override {
        cout << "Penguin is eating" << endl;
    }
};

int main() {
    Sparrow sparrow;
    sparrow.eat();
    sparrow.fly();

    Penguin penguin;
    penguin.eat();

    // This is correct: Penguin does NOT implement FlyingBird
    // So we don't try to call fly() on a penguin

    return 0;
}
