#include <iostream>
#include <memory>
#include <iomanip>
using namespace std;

// Open-Closed Principle: Open for extension, closed for modification

class ShippingStrategy {
public:
    virtual ~ShippingStrategy() = default;
    virtual double calculateCost(double weight) const = 0;
};

class StandardShipping : public ShippingStrategy {
public:
    double calculateCost(double weight) const override {
        return weight * 1.5;
    }
};

class ExpressShipping : public ShippingStrategy {
public:
    double calculateCost(double weight) const override {
        return weight * 3.0;
    }
};

class OvernightShipping : public ShippingStrategy {
public:
    double calculateCost(double weight) const override {
        return weight * 5.0;
    }
};

class InternationalShipping : public ShippingStrategy {
public:
    double calculateCost(double weight) const override {
        return weight * 10.0;
    }
};

class ShippingCostCalculator {
public:
    double calculate(const ShippingStrategy& strategy, double weight) const {
        return strategy.calculateCost(weight);
    }
};

int main() {
    ShippingCostCalculator calculator;

    cout << fixed << setprecision(2);
    cout << "Standard: $" << calculator.calculate(StandardShipping(), 2.0) << endl;
    cout << "Express: $" << calculator.calculate(ExpressShipping(), 2.0) << endl;
    cout << "Overnight: $" << calculator.calculate(OvernightShipping(), 2.0) << endl;
    cout << "International: $" << calculator.calculate(InternationalShipping(), 2.0) << endl;

    return 0;
}
