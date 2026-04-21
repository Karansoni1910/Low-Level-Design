# 🔄 Liskov Substitution Principle

**Definition:** The Liskov Substitution Principle (LSP) states that objects of a superclass should be **replaceable with objects of its subclasses without breaking the application**. In other words, derived classes must be substitutable for their base classes. Violating LSP leads to runtime errors and unexpected behavior.

---

## 📋 Problem Statement

You have a `Bird` class with `eat()` and `fly()` methods. A `Penguin` subclass extends `Bird` but **can't fly**, so it overrides `fly()` to throw an exception:

```java
// ❌ Violates LSP
class Bird {
    public void eat() { ... }
    public void fly() { ... }  // Penguins can't fly!
}

class Penguin extends Bird {
    public void eat() { ... }
    public void fly() {
        throw new UnsupportedOperationException("Penguins cannot fly");
    }
}

// Runtime crash!
Bird bird = new Penguin();
bird.fly();  // 💥 Exception thrown!
```

**Problems:**
- Client code crashes at runtime expecting a Bird to fly
- Penguin is not truly substitutable for Bird
- Violates the contract implied by the base class
- Hard to reason about code behavior
- Breaks polymorphism guarantees

Your task: **Refactor to respect LSP** by splitting Bird into appropriate interfaces.

---

## ✅ Requirements

### Bird Interface
- **Method:** `eat()` - All birds can eat
- Basic interface for all birds

### FlyingBird Interface
- **Extends:** Bird interface
- **Method:** `fly()` - Only for birds that can fly
- Add capabilities without forcing contracts

### Implementations
- **Sparrow** - Implements `FlyingBird` (can eat and fly)
- **Penguin** - Implements `Bird` (can eat only, NOT flying bird)

### Client Code Pattern
- Code working with any `Bird` - Never calls `fly()`
- Code needing flight - Accepts `FlyingBird` specifically
- No runtime exceptions or type casting

### Test Cases
- Sparrow can eat and fly
- Penguin can eat but cannot fly
- No runtime exceptions
- Type-safe substitution

---

## 📊 Violating vs Following LSP

### ❌ Violating LSP (Inheritance)
```
Bird (base class)
├─ fly() method

Sparrow extends Bird (✓ can fly)
    └─ fly() works

Penguin extends Bird (✗ cannot fly)
    └─ fly() throws exception
    └─ NOT substitutable!

(Runtime error when Penguin assigned to Bird)
```
**Problems:** Runtime crashes, broken contracts, unpredictable behavior

### ✅ Following LSP (Interface Segregation)
```
Bird (interface - general)
├─ eat()

FlyingBird extends Bird (specialized)
├─ fly()

Sparrow implements FlyingBird (✓ can do both)
    ├─ eat()
    └─ fly()

Penguin implements Bird (✓ can eat only)
    └─ eat()

(All classes truly substitutable for their interfaces)
```
**Benefits:** Type-safe, no runtime surprises, predictable behavior

---

## 🔑 Key Concepts Covered

- **Substitutability** - Subclasses are safe replacements for base classes
- **Interface Segregation** - Split responsibilities into focused interfaces
- **Contract Integrity** - Subclasses must honor base class contracts
- **Behavioral Consistency** - Derived classes should behave predictably
- **Type Safety** - Catch errors at compile time, not runtime
- **Polymorphism** - Polymorphism that actually works safely
- **Proper Hierarchy** - Use interfaces for capabilities, not implementation

---

## 💡 Why Liskov Substitution Principle Matters

| Issue | Impact |
|-------|--------|
| **Breaking substitutability** | Runtime crashes, unexpected exceptions |
| **Violated contracts** | Code assumes behaviors that don't exist |
| **Unreliable polymorphism** | Can't trust that subclasses work like base |
| **Type casting needed** | instanceof checks indicate LSP violation |
| **Maintenance nightmare** | Can't confidently extend class hierarchy |

By following LSP, we:
- ✅ Ensure safe substitution at runtime
- ✅ Create reliable polymorphic code
- ✅ Avoid runtime exceptions
- ✅ Build trustworthy inheritance hierarchies
- ✅ Enable confident code reuse
- ✅ Improve code predictability

---

## 📝 Signs of LSP Violations

Look for these red flags:

- 🚩 Overriding methods that throw exceptions
- 🚩 Empty method implementations
- 🚩 Type casting before method calls
- 🚩 instanceof checks in client code
- 🚩 Subclass narrows or restricts functionality
- 🚩 Subclass requires different preconditions
- 🚩 Subclass breaks invariants of parent
- 🚩 Comments like "Don't call this method on Subclass X"

---

## 💡 LSP and Other SOLID Principles

| Principle | Relationship |
|-----------|--------------|
| **SRP** | Each interface has single responsibility |
| **OCP** | LSP enables proper extension via interfaces |
| **ISP** | LSP often achieved through interface segregation |
| **DIP** | Depend on LSP-compliant interfaces |

---

## 📊 Real-World Examples

### Rectangle vs Square
```java
// ❌ Violates LSP
class Rectangle {
    void setWidth(int w) { ... }
    void setHeight(int h) { ... }
}

class Square extends Rectangle {
    void setWidth(int w) { super.setWidth(w); super.setHeight(w); }
    void setHeight(int h) { super.setWidth(h); super.setHeight(h); }
}

// Code expects: width and height independent
// Square violates this contract!

// ✅ Better design: Use Shape interface
interface Shape { double area(); }
class Rectangle implements Shape { ... }
class Square implements Shape { ... }
```

### Payment Processing
```java
// ❌ Violates LSP
class PaymentProcessor {
    void charge(CreditCard card) { ... }
}

class GiftCardProcessor extends PaymentProcessor {
    void charge(GiftCard card) {
        throw new NotSupportedException(); // Not substitutable!
    }
}

// ✅ Better design: Different types for different payments
interface Payment { void process(); }
class CreditCardPayment implements Payment { ... }
class GiftCardPayment implements Payment { ... }
```

---

## 🔗 How LSP Connects to Other SOLID Principles

1. **SRP** - Split responsibilities into focused interfaces
2. **OCP** - Create proper abstractions for safe extension
3. **ISP** - Design segregated interfaces that are properly implemented
4. **DIP** - Depend on abstractions that satisfy LSP
5. All work together for **truly reusable, maintainable code**