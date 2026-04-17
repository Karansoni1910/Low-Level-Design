# 📞 Interfaces

**Definition:** Interfaces define a contract of abstract methods that implementing classes must follow, enabling polymorphism and loose coupling between components.

---

## 📋 Problem Statement

Build a logging system where the format of log messages is configurable. A **Logger** class writes log messages, but the format (plain text vs. JSON) is determined by an injected **Formatter** interface.

---

## ✅ Requirements

### Formatter Interface
- **Method:** `format(message)` - Takes a string and returns a formatted string

### Implementations

| Class | Output Example |
|-------|----------------|
| **PlainFormatter** | `Server started on port 8080` |
| **JsonFormatter** | `{"log": "Server started on port 8080"}` |

### Logger Class
- Takes a **Formatter** in its constructor (dependency injection)
- **`log(message)`** - Formats the message using injected formatter, then prints it

---

## 💡 Key Concepts Covered

- Contract definition through interfaces
- Dependency injection and loose coupling
- Polymorphism through implementations
- Separation of concerns
- Strategy pattern