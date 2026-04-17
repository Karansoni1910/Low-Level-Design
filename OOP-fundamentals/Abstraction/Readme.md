# 🎭 Abstraction

**Definition:** Abstraction is the process of hiding complex implementation details and exposing only the essential features of an object through abstract classes and methods.

---

## 📋 Problem Statement

Build a shape calculation system using an abstract class. The abstract **Shape** class has abstract methods for calculating area and perimeter, plus a concrete `describe()` method that all shapes inherit.

---

## ✅ Requirements

### Abstract Shape Class
- **Abstract Methods:**
  - `area()` - Calculate the area of the shape
  - `perimeter()` - Calculate the perimeter of the shape
- **Concrete Method:**
  - `describe()` - Prints "Shape: [name], Area: [area], Perimeter: [perimeter]"

### Implementations

| Shape | Formula |
|-------|---------|
| **Circle** | Area = π × r² <br/> Perimeter = 2 × π × r |
| **Rectangle** | Area = width × height <br/> Perimeter = 2 × (width + height) |

### Key Feature
- The `describe()` method works for any shape without modification (polymorphism)

---

## 💡 Key Concepts Covered

- Abstract classes and methods
- Inheritance and method overriding
- Polymorphism in action
- Code reusability through abstraction
- Separation of interface from implementation