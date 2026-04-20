# 🔁 DRY - Don't Repeat Yourself

**Definition:** DRY (Don't Repeat Yourself) is a fundamental design principle that advocates eliminating code duplication by extracting common logic into reusable components. It promotes maintainability, reduces bugs, and makes code easier to update.

---

## 📋 Problem Statement

You have three region-specific order processors (`USOrderProcessor`, `EUOrderProcessor`, `UKOrderProcessor`) that each **duplicate the same tax calculation logic**. Your task is to extract a `TaxCalculator` interface with region-specific implementations, then refactor the order processors to use it.

This is a classic example of **violating DRY** - the same tax logic is written three times, making maintenance difficult and error-prone.

---

## ✅ Requirements

### TaxCalculator Interface
- **Method:** `calculateTax(amount)` - Returns calculated tax for a given amount
- **Method:** `getName()` - Returns the region name

### Region-Specific Implementations
- **USTaxCalculator** - 10% tax on amount
- **EUTaxCalculator** - 20% tax on amount
- **UKTaxCalculator** - 15% tax on amount

### OrderProcessor Class
- **Fields:** `taxCalculator` instance
- **Constructor:** Accepts a `TaxCalculator` for dependency injection
- **Method:** `processOrder(amount)` - Calculates and displays subtotal, tax, and total

---

## 📊 Before vs After

### ❌ Before (Violating DRY)
```
USOrderProcessor   → tax = amount * 0.10
EUOrderProcessor   → tax = amount * 0.20  (DUPLICATE LOGIC)
UKOrderProcessor   → tax = amount * 0.15  (DUPLICATE LOGIC)
```

### ✅ After (Following DRY)
```
TaxCalculator (Interface)
    ↓
USTaxCalculator, EUTaxCalculator, UKTaxCalculator
    ↓
OrderProcessor (uses TaxCalculator)
```

---

## 🔑 Key Concepts Covered

- **Code Reusability** - Extract common logic into shared components
- **Single Responsibility** - Each class has one reason to change
- **Maintainability** - Update tax logic in one place instead of three
- **Interface Segregation** - Define clean contracts for tax calculations
- **Dependency Injection** - Pass dependencies instead of hardcoding them
- **Reduced Bugs** - Less duplication means fewer places for bugs to hide

---

## 💡 Why DRY Matters

| Issue | Impact |
|-------|--------|
| **Code Duplication** | Hard to maintain, inconsistencies across codebase |
| **Bug Fixes** | Must fix bugs in multiple places |
| **Feature Changes** | Changes required in multiple locations |
| **Readability** | Code becomes bloated and harder to understand |

By following DRY, we centralize logic, improve consistency, and make the codebase more professional and scalable.