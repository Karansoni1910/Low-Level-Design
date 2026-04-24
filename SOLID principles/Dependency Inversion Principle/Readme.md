# 📋 Dependency Inversion Principle

**Definition:** The Dependency Inversion Principle (DIP) states that high-level modules should not depend on low-level modules. Both should depend on **abstractions**. It also means abstractions should not depend on details; details should depend on abstractions. This helps make code more flexible, testable, and easier to extend.

---

## 📋 Problem Statement

You have an `OrderService` class that directly creates and uses a concrete `MySQLDatabase` implementation:

```java
// ❌ Violates DIP (high-level module depends on concrete low-level module)
class OrderService {
	 private MySQLDatabase database = new MySQLDatabase();

	 public void placeOrder(String orderId, String orderData) {
		  database.insert("orders", orderData);
	 }
}
```

**Problems:**
- `OrderService` is tightly coupled to `MySQLDatabase`
- Switching to PostgreSQL or another database requires changing `OrderService`
- Hard to test because the dependency is created internally
- Violates Dependency Inversion Principle
- Reduces flexibility and maintainability

Your task: **Refactor the design so `OrderService` depends on a `Database` abstraction instead of a concrete database class.**

---

## ✅ Requirements

### Database
- **Responsibility:** Provide an abstraction for database operations
- **Methods:**
  - `insert(table, data)`
  - `query(table, id)`

### MySQLDatabase
- **Responsibility:** Concrete MySQL implementation of `Database`
- **Behavior:** Print messages starting with `MySQL: ...`

### PostgreSQLDatabase
- **Responsibility:** Concrete PostgreSQL implementation of `Database`
- **Behavior:** Print messages starting with `PostgreSQL: ...`

### OrderService
- **Responsibility:** Handle order-related business logic
- **Dependency:** Accept a `Database` through its constructor
- **Methods:**
  - `placeOrder(orderId, orderData)`
  - `getOrder(orderId)`

### Test Cases
- Place and fetch an order using `MySQLDatabase`
- Place and fetch an order using `PostgreSQLDatabase`
- Verify `OrderService` works with both implementations unchanged
- Verify high-level logic depends only on the `Database` abstraction

---

## 📊 Tight Coupling vs DIP

### ❌ Tight Coupling (Violating DIP)
```
OrderService
	↓ directly depends on
MySQLDatabase

(High-level policy depends on low-level detail)
```
**Problems:** Hard to swap implementations, difficult to test, fragile design

### ✅ Dependency Inversion (Following DIP)
```
OrderService
	↓ depends on
Database
	↑         ↑
MySQLDatabase PostgreSQLDatabase

(High-level and low-level both depend on abstraction)
```
**Benefits:** Loose coupling, easier testing, better extensibility, cleaner architecture

---

## 🔑 Key Concepts Covered

- **Dependency Inversion** - Depend on abstractions, not concrete classes
- **Loose Coupling** - High-level logic is isolated from low-level details
- **Constructor Injection** - Dependencies are provided from outside
- **Polymorphism** - Same service works with different database implementations
- **Testability** - Mock or fake databases can be injected easily
- **Maintainability** - Database changes do not force business logic changes

---

## 💡 Why DIP Matters

| Issue | Impact |
|-------|--------|
| **Concrete dependencies** | High-level modules become rigid and hard to change |
| **Tight coupling** | Small infrastructure changes ripple into business logic |
| **Poor testability** | Hard to replace real dependencies with test doubles |
| **Low flexibility** | Switching implementations requires modifying core code |
| **Harder maintenance** | Business logic and infrastructure become tangled |

By following DIP, we:
- ✅ Keep business logic independent of implementation details
- ✅ Make code easier to test and mock
- ✅ Support multiple implementations with the same high-level module
- ✅ Reduce maintenance cost when infrastructure changes
- ✅ Improve code flexibility and scalability

---

## 📝 How to Identify DIP Violations

Look for these red flags:
- 🚩 A class directly creates its own dependencies with `new`
- 🚩 High-level business logic imports concrete infrastructure classes
- 🚩 Swapping implementations requires editing core business classes
- 🚩 Unit tests require real databases, files, or networks
- 🚩 Abstractions are missing between policy and detail layers
- 🚩 One low-level change forces many high-level changes

---

## 🔗 DIP Relationship with Other SOLID Principles

| Principle | Relationship |
|-----------|--------------|
| **SRP** | Keeps business logic and infrastructure responsibilities separate |
| **OCP** | New implementations can be added without modifying high-level modules |
| **LSP** | Different implementations can substitute the same abstraction |
| **ISP** | Smaller, focused abstractions make dependency boundaries cleaner |

---

## 💡 Real-World Examples of DIP

- **Payment Systems** - Checkout service depends on a `PaymentGateway` interface, not Stripe or PayPal directly
- **Notification Systems** - Alert service depends on a `Notifier` abstraction, not email or SMS classes directly
- **Storage Layers** - Application depends on a `Storage` interface, not local disk or cloud providers directly
- **Logging** - Business services depend on a logger abstraction, not a specific logging framework
- **Database Access** - Services depend on repository or database interfaces, not concrete engines