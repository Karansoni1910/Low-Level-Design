# 🔒 Singleton Pattern

**Definition:** The Singleton Pattern ensures that a class has only **one instance** throughout the application lifecycle and provides a global point of access to that instance. This pattern is useful when exactly one object is needed to coordinate actions across the system.

---

## 📋 Problem Statement

Implement a **Counter singleton** that tracks a count across the entire application. Multiple components should be able to increment the counter, and all must see the same value, ensuring consistency and avoiding duplicate instances.

**Real-World Example:** A logging system, database connection pool, or application configuration manager where only one instance should exist.

---

## ✅ Requirements

### Counter Class (Singleton)
- **getInstance()** - Returns the single instance of Counter (lazy initialization)
- **increment()** - Increases the count by 1
- **getCount()** - Returns the current count value
- **Thread-Safe** - Concurrent increments must not lose updates
- **Single Instance Guarantee** - Calling `getInstance()` from different places returns the same object

---

## 🏗️ Implementation Approaches

### ✅ Recommended: Bill Pugh Singleton (Static Inner Class)
- Thread-safe without synchronization
- Lazy initialization
- Simple and efficient

### ✅ Alternative: Enum Singleton
- Most concise approach
- Inherently thread-safe
- Protection against serialization attacks

---

## 💡 Key Concepts Covered

- Single instance management
- Thread safety in concurrent environments
- Lazy initialization techniques
- Global access point pattern
- Bill Pugh inner class holder pattern

---

## 🎯 Common Use Cases

- 🔧 Configuration managers
- 📝 Logging systems
- 🗄️ Database connection pools
- 🔐 Cache managers
- 🎮 Game state managers