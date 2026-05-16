#include <iostream>
#include <iomanip>
using namespace std;

// DRY - Don't Repeat Yourself Principle

class TaxCalculator {
public:
    virtual ~TaxCalculator() = default;
    virtual double calculateTax(double amount) = 0;
    virtual string getName() = 0;
};

class USTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.10;
    }

    string getName() override {
        return "US";
    }
};

class EUTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.20;
    }

    string getName() override {
        return "EU";
    }
};

class UKTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.15;
    }

    string getName() override {
        return "UK";
    }
};

class OrderProcessor {
private:
    TaxCalculator* taxCalculator;

public:
    OrderProcessor(TaxCalculator* calc) : taxCalculator(calc) {}

    void processOrder(double amount) {
        double tax = taxCalculator->calculateTax(amount);
        double total = amount + tax;

        cout << fixed << setprecision(2);
        cout << taxCalculator->getName() << " Order - Subtotal: $" << amount
             << ", Tax: $" << tax << ", Total: $" << total << endl;
    }
};

int main() {
    USTaxCalculator usTax;
    EUTaxCalculator euTax;
    UKTaxCalculator ukTax;

    OrderProcessor usProcessor(&usTax);
    usProcessor.processOrder(100.0);

    OrderProcessor euProcessor(&euTax);
    euProcessor.processOrder(100.0);

    OrderProcessor ukProcessor(&ukTax);
    ukProcessor.processOrder(100.0);

    return 0;
}
