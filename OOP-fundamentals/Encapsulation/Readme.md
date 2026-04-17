# 🔐 Encapsulation

**Definition:** Encapsulation is the bundling of data and methods into a single unit while hiding internal implementation details through access modifiers (private, protected, public).

---

## 📋 Problem Statement

Build a **ShoppingCart** class that manages items, supports a one-time discount code, and prevents modifications after checkout.

---

## ✅ Requirements

| Method | Description |
|--------|-------------|
| **`addItem(name, price)`** | Adds an item, but only if the cart hasn't been checked out |
| **`applyDiscount(code)`** | If code is "SAVE10" and no discount applied yet, applies 10% discount. Returns success/failure |
| **`getTotal()`** | Returns sum of all prices, minus 10% if discount was applied |
| **`checkout()`** | Marks cart as checked out if it has at least one item. Prevents further modifications |

### Private Fields

- `items` - Map/dictionary of items (item name to price)
- `discountCode` - Can only be applied once
- `isCheckedOut` - Flag to prevent modifications after checkout

---

## 💡 Key Concepts Covered

- Data hiding with private fields
- Controlled access through public methods
- State validation and control flow
- Immutability after checkout