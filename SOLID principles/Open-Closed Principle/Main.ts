// Open-Closed Principle: Open for extension, closed for modification

interface ShippingStrategy {
    calculateCost(weight: number): number;
}

class StandardShipping implements ShippingStrategy {
    calculateCost(weight: number): number {
        return weight * 1.5;
    }
}

class ExpressShipping implements ShippingStrategy {
    calculateCost(weight: number): number {
        return weight * 3.0;
    }
}

class OvernightShipping implements ShippingStrategy {
    calculateCost(weight: number): number {
        return weight * 5.0;
    }
}

class InternationalShipping implements ShippingStrategy {
    calculateCost(weight: number): number {
        return weight * 10.0;
    }
}

class ShippingCostCalculator {
    calculate(strategy: ShippingStrategy, weight: number): number {
        return strategy.calculateCost(weight);
    }
}

// Usage
const calculator = new ShippingCostCalculator();

console.log("Standard: $" + calculator.calculate(new StandardShipping(), 2.0));
console.log("Express: $" + calculator.calculate(new ExpressShipping(), 2.0));
console.log("Overnight: $" + calculator.calculate(new OvernightShipping(), 2.0));
console.log(
    "International: $" + calculator.calculate(new InternationalShipping(), 2.0)
);
