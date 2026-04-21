import java.util.*;

// Before: One class doing three unrelated jobs
class OrderService {
    private Map<String, Integer> inventory = new HashMap<>();
    private List<String> orders = new ArrayList<>();

    public OrderService() {
        inventory.put("LAPTOP", 10);
        inventory.put("PHONE", 25);
        inventory.put("TABLET", 15);
    }

    public void placeOrder(String productId, int quantity, String customerEmail) {
        // Responsibility 1: Inventory check
        Integer stock = inventory.get(productId);
        if (stock == null || stock < quantity) {
            System.out.println("Insufficient stock for " + productId);
            return;
        }

        // Responsibility 2: Order processing
        double pricePerUnit = 100.0; // Simplified pricing
        double total = pricePerUnit * quantity;
        String orderId = "ORD-" + (orders.size() + 1);
        orders.add(orderId);

        // Responsibility 3: Update inventory
        inventory.put(productId, stock - quantity);

        // Responsibility 4: Send notification
        System.out.println("Email to " + customerEmail + ": Order " + orderId
            + " confirmed. Total: $" + total);
    }
}

// TODO: Refactor into OrderProcessor, InventoryManager, and NotificationService.

class OrderProcessor {
    private final InventoryManager inventoryManager;
    private final NotificationService notificationService;
    private List<String> orders = new ArrayList<>();

    public OrderProcessor(InventoryManager inventoryManager, NotificationService notificationService) {
        this.inventoryManager = inventoryManager;
        this.notificationService = notificationService;
        this.inventoryManager.put("LAPTOP", 10);
        this.inventoryManager.put("PHONE", 25);
        this.inventoryManager.put("TABLET", 15);
    }

    public void placeOrder(String productId, int quantity, String customerEmail) {
        int stock = inventoryManager.checkStock(productId, quantity);
        if(stock > quantity) {
            double pricePerUnit = 100.0; // Simplified pricing
            double total = pricePerUnit * quantity;
            String orderId = "ORD-" + (orders.size() + 1);
            orders.add(orderId);

            inventoryManager.put(productId, stock - quantity);

            notificationService.sendNotification(customerEmail, orderId, total);
        }

    }
}

class InventoryManager {
    private Map<String, Integer> inventory = new HashMap<>();

    public void put(String productId, int quantity) {
        inventory.put(productId, quantity);
    }

    public int checkStock(String productId, int quantity) {
        Integer stock = inventory.get(productId);
        if (stock == null || stock < quantity) {
            System.out.println("Insufficient stock for " + productId);
            return 0;
        }
        return stock;
    }
}

class NotificationService {
    public void sendNotification(String customerEmail, String orderId, double total) {
        System.out.println("Email to " + customerEmail + ": Order " + orderId
            + " confirmed. Total: $" + total);
    }
}

public class Main {
    public static void main(String[] args) {
        // After refactoring, usage should look like:
        // InventoryManager inventory = new InventoryManager();
        // NotificationService notifications = new NotificationService();
        // OrderProcessor processor = new OrderProcessor(inventory, notifications);
        // processor.placeOrder("LAPTOP", 2, "alice@example.com");
        InventoryManager inventory = new InventoryManager();
        NotificationService notifications = new NotificationService();
        OrderProcessor processor = new OrderProcessor(inventory, notifications);
        processor.placeOrder("LAPTOP", 2, "alice@example.com");
    }
}