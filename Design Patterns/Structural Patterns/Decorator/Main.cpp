#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Decorator Pattern

class Pizza {
public:
    virtual ~Pizza() = default;
    virtual double getCost() const = 0;
    virtual string getDescription() const = 0;
};

class PlainPizza : public Pizza {
public:
    double getCost() const override {
        return 5.00;
    }

    string getDescription() const override {
        return "Plain pizza";
    }
};

class PizzaDecorator : public Pizza {
protected:
    Pizza* pizza;

public:
    PizzaDecorator(Pizza* pizza) : pizza(pizza) {}
    virtual ~PizzaDecorator() { delete pizza; }

    double getCost() const override {
        return pizza->getCost();
    }

    string getDescription() const override {
        return pizza->getDescription();
    }
};

class CheeseDecorator : public PizzaDecorator {
public:
    CheeseDecorator(Pizza* pizza) : PizzaDecorator(pizza) {}

    double getCost() const override {
        return pizza->getCost() + 1.50;
    }

    string getDescription() const override {
        return pizza->getDescription() + ", cheese";
    }
};

class OliveDecorator : public PizzaDecorator {
public:
    OliveDecorator(Pizza* pizza) : PizzaDecorator(pizza) {}

    double getCost() const override {
        return pizza->getCost() + 2.00;
    }

    string getDescription() const override {
        return pizza->getDescription() + ", olives";
    }
};

class MushroomDecorator : public PizzaDecorator {
public:
    MushroomDecorator(Pizza* pizza) : PizzaDecorator(pizza) {}

    double getCost() const override {
        return pizza->getCost() + 1.00;
    }

    string getDescription() const override {
        return pizza->getDescription() + ", mushrooms";
    }
};

int main() {
    cout << fixed << setprecision(2);

    Pizza* plain = new PlainPizza();
    cout << plain->getDescription() << " | $" << plain->getCost() << endl;
    delete plain;

    Pizza* cheeseOlive = new OliveDecorator(new CheeseDecorator(new PlainPizza()));
    cout << cheeseOlive->getDescription() << " | $" << cheeseOlive->getCost() << endl;
    delete cheeseOlive;

    Pizza* loaded = new MushroomDecorator(
        new OliveDecorator(new CheeseDecorator(new PlainPizza())));
    cout << loaded->getDescription() << " | $" << loaded->getCost() << endl;
    delete loaded;

    return 0;
}
