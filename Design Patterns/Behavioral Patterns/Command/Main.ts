// --- Command Interface ---
interface OrderCommand {
    execute(): void;
    undo(): void;
}

// --- Receiver: Kitchen ---
class Kitchen {
    prepareDish(dish: string): void {
        console.log(`Preparing: ${dish}`);
    }

    cancelDish(dish: string): void {
        console.log(`Cancelling: ${dish}`);
    }
}

// --- Concrete Command 1: PlaceOrderCommand ---
class PlaceOrderCommand implements OrderCommand {
    private kitchen: Kitchen;
    private dish: string;

    constructor(kitchen: Kitchen, dish: string) {
        this.kitchen = kitchen;
        this.dish = dish;
    }

    execute(): void {
        this.kitchen.prepareDish(this.dish);
    }

    undo(): void {
        this.kitchen.cancelDish(this.dish);
    }
}

// --- Concrete Command 2: CancelOrderCommand ---
class CancelOrderCommand implements OrderCommand {
    private kitchen: Kitchen;
    private dish: string;

    constructor(kitchen: Kitchen, dish: string) {
        this.kitchen = kitchen;
        this.dish = dish;
    }

    execute(): void {
        this.kitchen.cancelDish(this.dish);
    }

    undo(): void {
        this.kitchen.prepareDish(this.dish);
    }
}

// --- Invoker: Waiter ---
class Waiter {
    private pending: OrderCommand[] = [];
    private history: OrderCommand[] = [];

    takeOrder(command: OrderCommand): void {
        this.pending.push(command);
    }

    submitOrders(): void {
        for (const command of this.pending) {
            command.execute();
            this.history.push(command);
        }
        this.pending = [];
    }

    undoLast(): void {
        if (this.history.length > 0) {
            const command = this.history.pop();
            if (command) {
                command.undo();
            }
        }
    }
}

// --- Main ---
const kitchen = new Kitchen();
const waiter = new Waiter();

// Queue orders
waiter.takeOrder(new PlaceOrderCommand(kitchen, "Pasta"));
waiter.takeOrder(new PlaceOrderCommand(kitchen, "Pizza"));
waiter.takeOrder(new PlaceOrderCommand(kitchen, "Burger"));

console.log("--- Submitting Orders ---");
waiter.submitOrders();

console.log("\n--- Undoing Last Order ---");
waiter.undoLast();

console.log("\n--- Undoing Another Order ---");
waiter.undoLast();
