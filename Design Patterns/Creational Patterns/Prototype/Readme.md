# 🎭 Prototype Pattern

**Definition:** The Prototype Pattern is a creational design pattern that creates new objects by copying an existing object (the prototype) rather than creating from scratch. This pattern is useful when object creation is expensive or when you need to create independent copies of complex objects without coupling to their concrete classes.

---

## 📋 Problem Statement

Implement a **Shape prototype system** with Circle and Rectangle classes. Each shape has a color and dimensions. Clone a circle and a rectangle, modify the clones, and verify the originals are unaffected.

**Real-World Example:** Drawing applications (cloning shapes), game development (spawning enemy units), document editors (copy-paste functionality), or prototype-based systems where creating new instances from templates is efficient.

---

## ✅ Requirements

### Shape Objects
- **Circle** - Has color and radius
- **Rectangle** - Has color, width, and height

### Cloneable Interface
- **clone()** - Returns an independent copy of the shape
- **Deep Copy** - Cloned objects must be independent (modifying clone doesn't affect original)

### Cloning Behavior
- After cloning, modifying the clone's properties must not affect the original
- Each cloned object is a separate instance with its own state

---

## 🎯 Key Features

- **Independent Copies:** Cloned objects are completely independent from originals
- **State Preservation:** All properties are copied to the new instance
- **Loose Coupling:** No dependency on concrete class constructors
- **Efficient Creation:** Avoids expensive object initialization

---

## 💡 Key Concepts Covered

- Object cloning and deep copying
- Prototype-based object creation
- Immutability through independent instances
- Separation of object creation from usage
- State replication patterns

---

## 🎯 Common Use Cases

- **Drawing Applications:** Cloning shapes and graphics
- **Game Development:** Spawning units from prototypes
- **Document Systems:** Copy-paste operations
- **Configuration Management:** Creating variants from templates
- **Caching:** Storing prototypes for quick instantiation