# 📋 Single Responsibility Principle

**Definition:** The Single Responsibility Principle (SRP) states that a class should have only **one reason to change**. In other words, a class should have only one job or responsibility. This principle is the foundation of good object-oriented design and makes code more maintainable, testable, and flexible.

---

## 📋 Problem Statement

You have an `OrderService` class that is a **"God Class"** handling multiple unrelated responsibilities:

```java
// ❌ Violates SRP (God Class)
class OrderService {
    public void placeOrder(String productId, int quantity, String customerEmail) {
        // Responsibility 1: Inventory check
        if (stock < quantity) { ... }
        
        // Responsibility 2: Order processing
        double total = pricePerUnit * quantity;
        String orderId = "ORD-" + (orders.size() + 1);
        
        // Responsibility 3: Inventory update
        inventory.put(productId, stock - quantity);
        
        // Responsibility 4: Send notification
        System.out.println("Email: Order confirmed");
    }
}
```

**Problems:**
- 4 different responsibilities in one class
- Multiple reasons to change
- Hard to test (must set up everything)
- Can't reuse individual concerns
- Violates Single Responsibility Principle

Your task: **Refactor into three focused classes** with single responsibilities.

---

## ✅ Requirements

### OrderProcessor
- **Responsibility:** Handle order validation and total calculation
- **Method:** `placeOrder(productId, quantity, customerEmail)` - Orchestrates the order process
- **Dependencies:** InventoryManager, NotificationService

### InventoryManager
- **Responsibility:** Handle stock checks and stock updates
- **Methods:**
  - `checkStock(productId, quantity)` - Check if enough stock exists
  - `updateStock(productId, quantity)` - Deduct from inventory
  - `put(productId, quantity)` - Add stock

### NotificationService
- **Responsibility:** Send order confirmation messages
- **Method:** `sendNotification(email, orderId, total)` - Send confirmation email

### Test Cases
- Place order with sufficient stock
- Place order with insufficient stock
- Verify inventory updated correctly
- Verify notification sent

---

## 📊 God Class vs SRP

### ❌ God Class (Violating SRP)
```
OrderService (Single bloated class)
├─ Order processing logic
├─ Inventory management logic
├─ Notification logic
└─ Too many responsibilities

(One class, multiple reasons to change)
```
**Problems:** Hard to test, maintain, extend, and reuse

### ✅ SRP (Following SRP)
```
OrderProcessor (Process orders only)
    ↓ depends on
InventoryManager (Manage inventory only)
    ↓
NotificationService (Send notifications only)

(Each class, one reason to change)
```
**Benefits:** Focused, testable, reusable, maintainable

---

## 🔑 Key Concepts Covered

- **Single Responsibility** - One class, one reason to change
- **High Cohesion** - Class members work toward single purpose
- **Low Coupling** - Depends on abstractions, not implementations
- **Testability** - Easy to test each responsibility independently
- **Reusability** - Classes can be used in different contexts
- **Maintainability** - Changes to one responsibility don't affect others
- **Flexibility** - Easy to extend with new implementations

---

## 💡 Why SRP Matters

| Issue | Impact |
|-------|--------|
| **Multiple responsibilities** | Multiple reasons to change (fragile) |
| **God classes** | Hard to understand, test, and maintain |
| **Tight coupling** | Changes affect unrelated functionality |
| **Low reusability** | Can't use parts independently |
| **Testing difficulty** | Must set up entire class for one test |

By following SRP, we:
- ✅ Improve code clarity and organization
- ✅ Reduce bugs and maintenance costs
- ✅ Increase code reusability
- ✅ Simplify testing and debugging
- ✅ Enable independent team work
- ✅ Make code more professional and scalable

---

## 📝 How to Identify SRP Violations

Look for these red flags:
- 🚩 Class name is vague (Manager, Service, Handler)
- 🚩 Class has multiple reasons to change
- 🚩 Hard to describe class purpose in one sentence
- 🚩 Class has too many methods
- 🚩 Class uses "and" or "or" in description
- 🚩 High number of dependencies
- 🚩 Low test coverage

---

## 🔗 SRP Relationship with Other SOLID Principles

| Principle | Relationship |
|-----------|--------------|
| **OCP** | SRP makes it easier to extend without modifying |
| **LSP** | Clear single purpose ensures proper substitution |
| **ISP** | Focused classes have focused interfaces |
| **DIP** | Single responsibility leads to cleaner abstractions |

---

## 💡 Examples of Responsibilities

- **Database Operations** - Persistence
- **Business Logic** - Core rules and calculations
- **Email Notifications** - Sending emails
- **Logging** - Recording events
- **Authentication** - User verification
- **Data Validation** - Input checking
- **Formatting** - Output presentation