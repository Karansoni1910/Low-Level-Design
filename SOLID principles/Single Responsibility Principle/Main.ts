// Single Responsibility Principle: Each class has one reason to change

class InventoryManager {
    private inventory: Map<string, number> = new Map();

    put(productId: string, quantity: number): void {
        this.inventory.set(productId, quantity);
    }

    checkStock(productId: string, quantity: number): number {
        const stock = this.inventory.get(productId);
        if (stock === undefined || stock < quantity) {
            console.log(`Insufficient stock for ${productId}`);
            return 0;
        }
        return stock;
    }
}

class NotificationService {
    sendNotification(
        customerEmail: string,
        orderId: string,
        total: number
    ): void {
        console.log(
            `Email to ${customerEmail}: Order ${orderId} confirmed. Total: $${total}`
        );
    }
}

class OrderProcessor {
    private inventoryManager: InventoryManager;
    private notificationService: NotificationService;
    private orders: string[] = [];

    constructor(
        inventoryManager: InventoryManager,
        notificationService: NotificationService
    ) {
        this.inventoryManager = inventoryManager;
        this.notificationService = notificationService;

        // Initialize inventory
        this.inventoryManager.put("LAPTOP", 10);
        this.inventoryManager.put("PHONE", 25);
        this.inventoryManager.put("TABLET", 15);
    }

    placeOrder(
        productId: string,
        quantity: number,
        customerEmail: string
    ): void {
        const stock = this.inventoryManager.checkStock(productId, quantity);

        if (stock > 0) {
            const pricePerUnit = 100.0;
            const total = pricePerUnit * quantity;
            const orderId = `ORD-${this.orders.length + 1}`;
            this.orders.push(orderId);

            this.inventoryManager.put(productId, stock - quantity);

            this.notificationService.sendNotification(
                customerEmail,
                orderId,
                total
            );
        }
    }
}

// Usage
const inventory = new InventoryManager();
const notifications = new NotificationService();
const processor = new OrderProcessor(inventory, notifications);

processor.placeOrder("LAPTOP", 2, "alice@example.com");
processor.placeOrder("PHONE", 1, "bob@example.com");
