// Encapsulation: Bundle data and methods, hide internal details

class ShoppingCart {
    private items: Map<string, number> = new Map();
    private discountApplied: boolean = false;
    private isCheckedOut: boolean = false;

    addItem(name: string, price: number): void {
        if (!this.isCheckedOut) {
            this.items.set(name, price);
        } else {
            console.log("Cannot modify a checked-out cart");
        }
    }

    applyDiscount(code: string): boolean {
        if (!this.discountApplied && code === "SAVE10") {
            this.discountApplied = true;
            return true;
        }
        return false;
    }

    getTotal(): number {
        let total = 0;
        this.items.forEach(price => {
            total += price;
        });

        if (this.discountApplied) {
            total -= total / 10;
        }

        return Math.round(total * 100) / 100;
    }

    checkout(): void {
        if (this.items.size > 0 && !this.isCheckedOut) {
            this.isCheckedOut = true;
        }
    }

    getItems(): Map<string, number> {
        return new Map(this.items);
    }
}

// Usage
const cart = new ShoppingCart();
cart.addItem("Laptop", 999.99);
cart.addItem("Mouse", 29.99);

console.log("Total: $" + cart.getTotal());            // 1029.98

console.log("Discount: " + cart.applyDiscount("SAVE10")); // true
console.log("Total: $" + cart.getTotal());            // 926.98

console.log("Discount: " + cart.applyDiscount("SAVE10")); // false

cart.checkout();
cart.addItem("Keyboard", 79.99);  // Should be rejected
console.log("Total: $" + cart.getTotal());            // 926.98
