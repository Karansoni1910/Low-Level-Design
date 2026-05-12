// DRY Principle: Don't Repeat Yourself
// Extract tax calculation logic into an interface/classes

interface TaxCalculator {
    calculateTax(amount: number): number;
    getName(): string;
}

class USTaxCalculator implements TaxCalculator {
    calculateTax(amount: number): number {
        return amount * 0.1;
    }

    getName(): string {
        return "US";
    }
}

class EUTaxCalculator implements TaxCalculator {
    calculateTax(amount: number): number {
        return amount * 0.2;
    }

    getName(): string {
        return "EU";
    }
}

class UKTaxCalculator implements TaxCalculator {
    calculateTax(amount: number): number {
        return amount * 0.15;
    }

    getName(): string {
        return "UK";
    }
}

class OrderProcessor {
    private taxCalculator: TaxCalculator;

    constructor(taxCalculator: TaxCalculator) {
        this.taxCalculator = taxCalculator;
    }

    processOrder(amount: number): void {
        const tax = this.taxCalculator.calculateTax(amount);
        const total = amount + tax;
        console.log(
            `${this.taxCalculator.getName()} Order - Subtotal: $${amount.toFixed(2)}, Tax: $${tax.toFixed(2)}, Total: $${total.toFixed(2)}`
        );
    }
}

// Usage
const usProcessor = new OrderProcessor(new USTaxCalculator());
usProcessor.processOrder(100.0);

const euProcessor = new OrderProcessor(new EUTaxCalculator());
euProcessor.processOrder(100.0);

const ukProcessor = new OrderProcessor(new UKTaxCalculator());
ukProcessor.processOrder(100.0);
