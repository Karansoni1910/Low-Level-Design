class ShippingCostCalculator {
    public double calculate(ShippingStrategy shippingStrategy, double weight) {
        return shippingStrategy.calculateCost(weight);
    }
}

// Usage
public class Main {
    public static void main(String[] args) {
        ShippingCostCalculator calculator = new ShippingCostCalculator();
        System.out.println("Standard: $" + calculator.calculate(new StandardShipping(), 2.0));
        System.out.println("Express: $" + calculator.calculate(new ExpressShipping(), 2.0));
        System.out.println("Overnight: $" + calculator.calculate(new OvernightShipping(), 2.0));
        System.out.println("International: $" + calculator.calculate(new InternationalShipping(), 2.0));
    }
}

interface ShippingStrategy {
    public double calculateCost(double weight);
}

class StandardShipping implements ShippingStrategy {
    public double calculateCost(double weight) {
        return weight * 1.5;
    }
}
class ExpressShipping implements ShippingStrategy {
    public double calculateCost(double weight) {
        return weight * 3.0;
    }
}
class OvernightShipping implements ShippingStrategy {
    public double calculateCost(double weight) {
        return weight * 5.0;
    }
}
class InternationalShipping implements ShippingStrategy {
    public double calculateCost(double weight) {
        return weight * 10.0;
    }
}

// TODO: Define a ShippingStrategy interface with a calculateCost(weight) method.
// TODO: Create concrete implementations for each shipping type.
// TODO: Refactor ShippingCostCalculator to accept a ShippingStrategy.