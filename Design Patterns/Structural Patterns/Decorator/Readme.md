# 🎨 Decorator Pattern

**Definition:** The Decorator Pattern is a structural design pattern that allows you to add new functionality to objects dynamically without altering their structure. It provides a flexible alternative to subclassing for extending an object's behavior. This pattern is particularly useful when you need to add multiple combinations of features to an object.

---

## 📋 Problem Statement

Implement a **Pizza Topping System** where customers can dynamically add toppings to a base pizza. Each topping adds to the cost and description. Avoid creating numerous subclasses for every topping combination by using decorators to wrap the pizza object with additional features.

**Real-World Example:** Coffee shop ordering systems with add-ons, text formatting with decorators (bold, italic, underline), GUI components with scrollbars and borders, HTTP request/response handling, or feature flags and optional enhancements.

---

## ✅ Requirements

### Component Interface (Pizza)
- **getCost()** - Returns the total cost as a double
- **getDescription()** - Returns the pizza description as a String

### Concrete Component (PlainPizza)
- Base cost: $5.00
- Description: "Plain pizza"

### Decorators (PizzaDecorator - Abstract)
- **CheeseDecorator** - Adds $1.50 to cost, appends ", cheese" to description
- **OliveDecorator** - Adds $2.00 to cost, appends ", olives" to description
- **MushroomDecorator** - Adds $1.00 to cost, appends ", mushrooms" to description
- Each decorator wraps a Pizza object and delegates calls while adding its own enhancements

---

## 🎯 Key Features

- **Dynamic Behavior Addition:** Add features to objects at runtime, not compile-time
- **Flexible Combinations:** Combine multiple decorators in any order
- **Single Responsibility:** Each decorator handles one specific enhancement
- **Composition over Inheritance:** Avoid explosion of subclasses for every feature combination
- **Open/Closed Principle:** Easy to add new decorators without modifying existing code

---

## 💡 Key Concepts Covered

- Wrapper pattern and object composition
- Recursive object wrapping with decorators
- Delegation and forwarding of method calls
- Alternative to inheritance for extending functionality
- Flexible feature composition and stacking
- Runtime behavior modification

---

## 🎯 Common Use Cases

- **Coffee/Pizza Ordering Systems:** Add-ons like extra shots, syrups, toppings
- **Text Formatting:** Decorators for bold, italic, underline, color, shadow effects
- **GUI Components:** Add borders, scrollbars, shadows to existing components
- **HTTP Handling:** Request/response interceptors, logging, compression, authentication
- **Feature Flags:** Conditionally add features or logging to functionality
- **Pricing Systems:** Dynamic surcharges, discounts, and additional fees
- **Stream Processing:** Buffering, compression, and encryption layers