# 📋 Interface Segregation Principle

**Definition:** The Interface Segregation Principle (ISP) states that clients should not be forced to depend on methods they do not use. Instead of one large interface, we should create **small, focused interfaces** so each class implements only the capabilities it actually needs.

---

## 📋 Problem Statement

You have a `MultiFunctionDevice` interface that mixes together multiple unrelated operations:

```java
// ❌ Violates ISP (fat interface)
interface MultiFunctionDevice {
	void print(String document);
	void scan(String document);
	void fax(String document, String number);
	void staple(String document);
}

class BasicPrinter implements MultiFunctionDevice {
	public void print(String document) { ... }
	public void scan(String document) { throw new UnsupportedOperationException(); }
	public void fax(String document, String number) { throw new UnsupportedOperationException(); }
	public void staple(String document) { throw new UnsupportedOperationException(); }
}
```

**Problems:**
- One interface forces all devices to support every feature
- Simple devices depend on methods they do not need
- Empty methods or `UnsupportedOperationException` become common
- Code becomes harder to maintain and extend
- Violates Interface Segregation Principle

Your task: **Refactor the fat interface into small capability-based interfaces**.

---

## ✅ Requirements

### Printable
- **Responsibility:** Provide printing capability
- **Method:** `print(document)`
- **Used by:** BasicPrinter, OfficePrinter, FullDevice

### Scannable
- **Responsibility:** Provide scanning capability
- **Method:** `scan(document)`
- **Used by:** OfficePrinter, FullDevice

### Faxable
- **Responsibility:** Provide faxing capability
- **Method:** `fax(document, number)`
- **Used by:** OfficePrinter, FullDevice

### Stapleable
- **Responsibility:** Provide stapling capability
- **Method:** `staple(document)`
- **Used by:** FullDevice

### Device Implementations
- `BasicPrinter` implements only `Printable`
- `OfficePrinter` implements `Printable`, `Scannable`, and `Faxable`
- `FullDevice` implements all four focused interfaces
- No class should contain empty methods or throw `UnsupportedOperationException`

### Test Cases
- Print a document using `BasicPrinter`
- Print, scan, and fax using `OfficePrinter`
- Print, scan, fax, and staple using `FullDevice`
- Verify each device exposes only the operations it supports

---

## 📊 Fat Interface vs ISP

### ❌ Fat Interface (Violating ISP)
```
MultiFunctionDevice
├─ print()
├─ scan()
├─ fax()
└─ staple()

BasicPrinter forced to depend on scan/fax/staple
```
**Problems:** Unused methods, rigid design, unsupported operations

### ✅ Interface Segregation (Following ISP)
```
Printable   Scannable   Faxable   Stapleable
	↑           ↑          ↑           ↑
BasicPrinter  OfficePrinter         FullDevice
			  FullDevice
```
**Benefits:** Focused contracts, cleaner implementations, better extensibility

---

## 🔑 Key Concepts Covered

- **Interface Segregation** - Split large interfaces into smaller role-based contracts
- **Capability-Based Design** - Each interface represents one behavior
- **Loose Coupling** - Clients depend only on the features they use
- **Cleaner Implementations** - No dummy methods or unsupported operations
- **Extensibility** - New device types can mix only the needed capabilities
- **Maintainability** - Changes in one capability do not affect unrelated devices

---

## 💡 Why ISP Matters

| Issue | Impact |
|-------|--------|
| **Fat interfaces** | Force classes to depend on irrelevant methods |
| **Unsupported operations** | Lead to fragile runtime behavior |
| **Tight coupling** | Changes ripple into unrelated implementations |
| **Poor readability** | Hard to understand what a class actually supports |
| **Reduced flexibility** | Difficult to compose different device capabilities |

By following ISP, we:
- ✅ Keep interfaces small and meaningful
- ✅ Prevent unnecessary dependencies
- ✅ Avoid empty methods and runtime exceptions
- ✅ Make implementations easier to test and reuse
- ✅ Support flexible composition of features
- ✅ Improve overall design clarity

---

## 📝 How to Identify ISP Violations

Look for these red flags:
- 🚩 An interface has too many methods
- 🚩 Implementations leave methods empty
- 🚩 Classes throw `UnsupportedOperationException`
- 🚩 Clients use only a small subset of an interface
- 🚩 Unrelated behaviors are grouped into one contract
- 🚩 Adding one feature forces many classes to change

---

## 🔗 ISP Relationship with Other SOLID Principles

| Principle | Relationship |
|-----------|--------------|
| **SRP** | Small interfaces keep responsibilities focused |
| **OCP** | Focused contracts make extension easier without modifying existing code |
| **LSP** | Smaller, accurate interfaces improve substitutability |
| **DIP** | Consumers can depend on precise abstractions instead of broad ones |

---

## 💡 Real-World Examples of ISP

- **Payment Systems** - Separate interfaces for refunds, recurring billing, and payouts
- **User Roles** - Different contracts for admin, editor, and viewer capabilities
- **File Handling** - Readable, Writable, and Deletable interfaces instead of one giant file contract
- **Notifications** - EmailSender, SmsSender, and PushNotifier as independent capabilities
- **Devices** - Printers, scanners, and fax machines with only the features they support