// Before: Each processor duplicates tax calculation
interface TaxCalculator {
    public double calculateTax(double amount);
    public String getName();
}

class USTaxCalculator implements TaxCalculator {
    public double calculateTax(double amount){
        return amount * 0.10;
    }
    public String getName() {return "US";}
}

class EUTaxCalculator implements TaxCalculator {
    public double calculateTax(double amount){
        return amount * 0.20;
    }
    
    public String getName() { return "EU"; }
}

class UKTaxCalculator implements TaxCalculator {
    public double calculateTax(double amount){
        return amount * 0.15;
    }
    
    public String getName() { return "UK"; }
}

class OrderProcessor {
    private TaxCalculator taxCalculator;
    OrderProcessor(TaxCalculator taxCalculator) {
        this.taxCalculator = taxCalculator;
    }

    public void processOrder(double amount) {
        double tax = taxCalculator.calculateTax(amount);
        double total = amount + tax;
        System.out.println(taxCalculator.getName() + " Order - Subtotal: $" + String.format("%.2f", amount)
            + ", Tax: $" + String.format("%.2f", tax) + ", Total: $" + String.format("%.2f", total));
    }
}

// TODO: Extract a TaxCalculator interface and region implementations.
// TODO: Refactor OrderProcessor to accept a TaxCalculator.

public class Main {
    public static void main(String[] args) {
        // After refactoring, usage should look like:
        // OrderProcessor usProcessor = new OrderProcessor(new USTaxCalculator());
        // usProcessor.processOrder(100.0);
        OrderProcessor usProcessor = new OrderProcessor(new USTaxCalculator());
        usProcessor.processOrder(100.0);
        OrderProcessor euProcessor = new OrderProcessor(new EUTaxCalculator());
        euProcessor.processOrder(100.0);
        OrderProcessor ukProcessor = new OrderProcessor(new UKTaxCalculator());
        ukProcessor.processOrder(100.0);
    }
}