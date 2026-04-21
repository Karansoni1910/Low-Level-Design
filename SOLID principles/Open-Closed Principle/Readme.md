# 📖 Open-Closed Principle

**Definition:** The Open-Closed Principle (OCP) states that software entities (classes, modules, functions) should be **open for extension but closed for modification**. This means you should be able to add new functionality without changing existing code. This reduces bugs and makes the system more maintainable.

---

## 📋 Problem Statement

You have a `ShippingCostCalculator` that uses **if-else chains** to determine shipping cost based on type:

```java
// ❌ Violates OCP (Closed for Extension)
class ShippingCostCalculator {
    public double calculate(String type, double weight) {
        if (type.equals("Standard")) {
            return weight * 1.5;
        } else if (type.equals("Express")) {
            return weight * 3.0;
        } else if (type.equals("Overnight")) {
            return weight * 5.0;
        } else if (type.equals("International")) {
            return weight * 10.0;
        }
        return 0;
    }
}
```

**Problems:**
- Every new shipping type requires modifying the calculator (closed for extension)
- Violates OCP - must change existing code for new functionality
- Hard to test new types in isolation
- Risk of introducing bugs when modifying existing code

Your task: **Make the calculator open for extension** by using the Strategy pattern so new shipping types can be added without modification.

---

## ✅ Requirements

### ShippingStrategy Interface
- **Method:** `calculateCost(weight)` - Returns shipping cost for given weight

### Shipping Implementations
- **StandardShipping** - Cost: weight × 1.5
- **ExpressShipping** - Cost: weight × 3.0
- **OvernightShipping** - Cost: weight × 5.0
- **InternationalShipping** - Cost: weight × 10.0

### ShippingCostCalculator Refactoring
- **Method:** `calculate(ShippingStrategy strategy, weight)` - Delegates to strategy
- Accept `ShippingStrategy` interface (not concrete types)
- No if-else chains
- No modification needed when adding new types

### Test Cases
- Standard shipping: 2kg → $3.0
- Express shipping: 2kg → $6.0
- Overnight shipping: 2kg → $10.0
- International shipping: 2kg → $20.0
- Adding new shipping type requires no modifications to existing code

---

## 📊 Closed vs Open for Extension

### ❌ Closed for Extension (Violating OCP)
```
ShippingCostCalculator
├─ if type == "Standard"
├─ else if type == "Express"
├─ else if type == "Overnight"
├─ else if type == "International"
└─ MUST MODIFY to add new type!

(Changing existing code is risky)
```
**Problems:** Hard to extend, risk of bugs, violates OCP

### ✅ Open for Extension (Following OCP)
```
ShippingCostCalculator
    ↓
ShippingStrategy (Interface)
    ├─ StandardShipping (NEW types added HERE)
    ├─ ExpressShipping
    ├─ OvernightShipping
    ├─ InternationalShipping
    └─ FedexShipping (NEW - no changes to calculator!)

(Add new implementations without modifying calculator)
```
**Benefits:** Extensible, maintainable, safe

---

## 🔑 Key Concepts Covered

- **Open for Extension** - Add new functionality via new classes
- **Closed for Modification** - Don't change existing working code
- **Strategy Pattern** - Choose algorithm at runtime
- **Polymorphism** - Same interface, different implementations
- **Abstraction** - Depend on interfaces, not concrete classes
- **Separation of Concerns** - Each strategy handles one type
- **Single Responsibility** - Each class does one thing

---

## 💡 Why Open-Closed Principle Matters

| Issue | Impact |
|-------|--------|
| **Modification of existing code** | High risk of introducing bugs |
| **If-else chains** | Hard to test, maintain, and extend |
| **Tight coupling to types** | Can't add new types independently |
| **Low extensibility** | System can't grow without changes |
| **Testing nightmare** | Must test all cases when adding new type |

By following OCP, we:
- ✅ Add new features without changing existing code
- ✅ Reduce bug risk (existing code unchanged)
- ✅ Improve testability (test new implementation independently)
- ✅ Enable independent team work
- ✅ Make code more professional and maintainable
- ✅ Create flexible, extensible systems

---

## 📝 Techniques for OCP

### 1. **Strategy Pattern** (Used in this example)
```java
// New shipping type added without modifying calculator
class FedexShipping implements ShippingStrategy {
    public double calculateCost(double weight) {
        return weight * 7.5;
    }
}
```

### 2. **Template Method Pattern**
```java
abstract class ShippingBase {
    public double calculateCost(double weight) {
        double baseCost = getBaseRate();
        double tax = calculateTax(weight);
        return (weight * baseCost) + tax;
    }
    
    protected abstract double getBaseRate();
}
```

### 3. **Decorator Pattern**
```java
class InsuredShipping implements ShippingStrategy {
    private ShippingStrategy inner;
    
    public double calculateCost(double weight) {
        return inner.calculateCost(weight) + 5.0; // Add insurance
    }
}
```

---

## 🔗 OCP Relationship with Other SOLID Principles

| Principle | Relationship |
|-----------|--------------|
| **SRP** | Each shipping type (single responsibility) |
| **LSP** | All strategies are properly substitutable |
| **ISP** | Clean ShippingStrategy interface |
| **DIP** | Depend on ShippingStrategy, not concrete types |

---

## ⚠️ OCP Anti-patterns to Avoid

- ❌ If-else chains for type checking
- ❌ Type casting and instanceof checks
- ❌ Modifying classes frequently
- ❌ Hardcoding new types
- ❌ Over-engineering (YAGNI balance)