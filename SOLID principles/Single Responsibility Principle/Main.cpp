#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Single Responsibility Principle: Each class has one responsibility

class InventoryManager {
private:
    map<string, int> inventory;

public:
    InventoryManager() {
        inventory["LAPTOP"] = 10;
        inventory["PHONE"] = 25;
        inventory["TABLET"] = 15;
    }

    void put(const string& productId, int quantity) {
        inventory[productId] = quantity;
    }

    int checkStock(const string& productId, int quantity) {
        auto it = inventory.find(productId);
        if (it == inventory.end() || it->second < quantity) {
            cout << "Insufficient stock for " << productId << endl;
            return 0;
        }
        return it->second;
    }
};

class NotificationService {
public:
    void sendNotification(const string& customerEmail, const string& orderId, double total) {
        cout << "Email to " << customerEmail << ": Order " << orderId
             << " confirmed. Total: $" << total << endl;
    }
};

class OrderProcessor {
private:
    InventoryManager& inventoryManager;
    NotificationService& notificationService;
    vector<string> orders;

public:
    OrderProcessor(InventoryManager& inv, NotificationService& notif)
        : inventoryManager(inv), notificationService(notif) {}

    void placeOrder(const string& productId, int quantity, const string& customerEmail) {
        int stock = inventoryManager.checkStock(productId, quantity);
        if (stock > quantity) {
            double pricePerUnit = 100.0;
            double total = pricePerUnit * quantity;
            string orderId = "ORD-" + to_string(orders.size() + 1);
            orders.push_back(orderId);

            inventoryManager.put(productId, stock - quantity);
            notificationService.sendNotification(customerEmail, orderId, total);
        }
    }
};

int main() {
    InventoryManager inventory;
    NotificationService notifications;
    OrderProcessor processor(inventory, notifications);

    processor.placeOrder("LAPTOP", 2, "alice@example.com");

    return 0;
}
