# 🏗️ Factory Method Pattern

**Definition:** The Factory Method Pattern defines an interface for creating objects, but leaves the decision of which class to instantiate to subclasses. It promotes loose coupling by eliminating the need for client code to directly instantiate concrete classes.

---

## 📋 Problem Statement

Build a **shape drawing system** using the Factory Method pattern. Each shape should have an `area()` method to calculate its area and a `describe()` method that prints the shape's name along with its calculated area.

**Real-World Example:** A UI framework that creates different button types (Windows, Mac, Linux buttons) using factory methods, or a graphics library that creates different shape objects without exposing concrete implementation details.

---

## ✅ Requirements

### Product Interface
- **`Shape`** interface with two methods:
  - `area()` - Returns the calculated area
  - `describe()` - Prints shape name and area (formatted to 2 decimal places)

### Concrete Products
| Shape | Dimensions | Formula |
|-------|-----------|---------|
| **Circle** | radius = 5 | π × r² |
| **Rectangle** | width = 4, height = 6 | width × height |
| **Triangle** | base = 3, height = 8 | 0.5 × base × height |

### Creator Hierarchy
- **`ShapeCreator`** (abstract class) - Defines factory method `createShape()` and a `describe()` method
- **`CircleCreator`** - Creates Circle instances
- **`RectangleCreator`** - Creates Rectangle instances
- **`TriangleCreator`** - Creates Triangle instances

---

## 💡 Key Concepts Covered

- Object creation abstraction through factory methods
- Loose coupling between client and concrete classes
- Polymorphism for flexible object instantiation
- Separation of creation logic from business logic
- How subclasses control which concrete class to instantiate

---

## 🎯 Common Use Cases

- UI frameworks creating different platform-specific components
- Database connection factories
- Logger implementations
- Document parsers for different file formats
- Game object creation systems