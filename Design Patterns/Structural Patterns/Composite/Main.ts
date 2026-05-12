interface Menu {
    display(indent: string): void;
    getItemCount(): number;
}

class MenuItem implements Menu {
    private name: string;
    private price: number;

    constructor(name: string, price: number) {
        this.name = name;
        this.price = price;
    }

    display(indent: string): void {
        console.log(`${indent}${this.name} - $${this.price.toFixed(2)}`);
    }

    getItemCount(): number {
        return 1;
    }
}

class SubMenu implements Menu {
    private name: string;
    private children: Menu[] = [];

    constructor(name: string) {
        this.name = name;
    }

    addItem(item: Menu): void {
        this.children.push(item);
    }

    display(indent: string): void {
        console.log(indent + this.name + ":");

        for (const child of this.children) {
            child.display(indent + "  ");
        }
    }

    getItemCount(): number {
        let total = 0;
        for (const child of this.children) {
            total += child.getItemCount();
        }
        return total;
    }
}

// Usage
const burger = new MenuItem("Burger", 8.99);
const fries = new MenuItem("Fries", 3.99);
const cola = new MenuItem("Cola", 1.99);
const water = new MenuItem("Water", 0.99);

const drinks = new SubMenu("Drinks");
drinks.addItem(cola);
drinks.addItem(water);

const mainMenu = new SubMenu("Main Menu");
mainMenu.addItem(burger);
mainMenu.addItem(fries);
mainMenu.addItem(drinks);

mainMenu.display("");
console.log("\nTotal items: " + mainMenu.getItemCount());
