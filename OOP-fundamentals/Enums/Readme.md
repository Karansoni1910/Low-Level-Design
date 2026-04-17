# 🚦 Enums

**Definition:** Enums are a special data type that define a fixed set of named constants, providing type-safe representations of predefined values.

---

## 📋 Problem Statement

Create a **TrafficLight** enum where each light has a color (RED, YELLOW, GREEN), a duration in seconds, and a `next()` method that returns the next light in the cycle.

---

## ✅ Requirements

| Light | Duration | Next |
|-------|----------|------|
| 🔴 RED | 30s | → GREEN |
| 🟢 GREEN | 25s | → YELLOW |
| 🟡 YELLOW | 5s | → RED |

### Methods

- **`next()`** - Returns the next TrafficLight in the cycle (RED → GREEN → YELLOW → RED)
- **`display()`** - Prints the color and duration

---

## 💡 Key Concepts Covered

- Type-safe constant definition
- State transitions and cycles
- Method implementation in enums
- Improved code readability and maintainability