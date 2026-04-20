# 📞 Law of Demeter

**Definition:** The Law of Demeter (also known as "Tell, Don't Ask") is a principle that states an object should only interact with its immediate neighbors, not reach through multiple levels of objects. This is also called **avoid train wrecks** - chains of method calls like `object.getX().getY().getZ()`.

---

## 📋 Problem Statement

You have an `OrderSummaryPrinter` that uses **train wreck chains** to access nested data:

```java
// ❌ Violates Law of Demeter (Train Wreck)
order.getCustomer().getAddress().getCity()
order.getPayment().getCreditCard().getLast4Digits()
```

**Problems:**
- Tightly coupled to internal structure
- Breaks if any intermediate object changes
- Violates encapsulation
- Hard to maintain and test

Your task: **Add delegation methods to Order** so the printer never reaches past it.

---

## ✅ Requirements

### Add Delegation Methods to Order
- `getCustomerCity()` - Returns customer's city
- `getPaymentLast4Digits()` - Returns last 4 digits of payment card

### OrderSummaryPrinter Refactoring
- Printer should only call methods directly on `Order`
- No chain calls through nested objects
- Handle null/empty cases gracefully

### Test Cases
- Order with valid customer and payment
- Display: "Ship to: [city]"
- Display: "Paid with card ending in: [last4]"

---

## 📊 Train Wreck vs Delegation

### ❌ Train Wreck (Violating LoD)
```
OrderSummaryPrinter
    ↓
order.getCustomer()
    ↓
customer.getAddress()
    ↓
address.getCity()

(Printer knows entire object hierarchy!)
```
**Problems:** Multiple levels of coupling, fragile code

### ✅ Delegation (Following LoD)
```
OrderSummaryPrinter
    ↓
order.getCustomerCity()
    ↓
Order (encapsulates complexity)
    ↓
customer → address → city

(Printer only knows Order!)
```
**Benefits:** Encapsulated, maintainable, loosely coupled

---

## 🔑 Key Concepts Covered

- **Encapsulation** - Hide internal object structure
- **Loose Coupling** - Objects don't know about neighbors' neighbors
- **Delegation Pattern** - Provide simple methods that encapsulate complex operations
- **Tell, Don't Ask** - Tell objects what to do, don't ask for their internals
- **Maintainability** - Changes to internal structure don't affect clients
- **Testability** - Easier to mock and test with delegated methods

---

## 💡 Why Law of Demeter Matters

| Issue | Impact |
|-------|--------|
| **Train wrecks** | Hard to read, maintain, and understand |
| **Tight coupling** | Changes cascade through the codebase |
| **Fragile code** | Breaks when intermediate objects change |
| **Poor encapsulation** | Internal structure exposed to clients |
| **Testing nightmare** | Hard to mock deep object hierarchies |

By following Law of Demeter, we:
- ✅ Reduce coupling between objects
- ✅ Improve maintainability
- ✅ Make code more readable
- ✅ Enhance flexibility and adaptability
- ✅ Simplify unit testing

---

## 📝 Law of Demeter Rules

An object should only call methods on:
1. **Itself** - `this.method()`
2. **Parameters** - Methods passed in
3. **Objects it creates** - `new Object()`
4. **Direct properties** - Objects it owns (via delegation)

❌ DON'T call methods on the return values of other methods (train wrecks)

---

## 🔗 Related Principles

- **Encapsulation** - Hide implementation details
- **DRY** - Don't repeat access patterns
- **Interface Segregation** - Only expose what's needed