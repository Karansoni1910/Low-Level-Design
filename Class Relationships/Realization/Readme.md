# 🔌 Realization (Interface Implementation)

**Definition:** Realization is a relationship between an interface and a concrete class that implements it. A class realizes an interface by providing concrete implementations for all abstract methods defined in the interface.

---

## 📋 Problem Statement

Build a text editor plugin system. A **Plugin** interface defines what every plugin can do, and a **TextEditor** loads and runs plugins through the interface without knowing their concrete types.

---

## ✅ Requirements

### Plugin Interface
- **Methods:**
  - `execute(text)` - Takes text and returns the processed text
  - `getName()` - Returns the plugin name

### Plugin Implementations

| Class | Functionality |
|-------|---------------|
| **SpellCheckPlugin** | Converts common misspellings (e.g., "teh" → "the", "adn" → "and") |
| **WordCountPlugin** | Appends word count to the text |
| **UpperCasePlugin** | Converts text to uppercase |

### TextEditor Class
- **Fields:** List of `Plugin` objects
- **Methods:**
  - `registerPlugin(plugin)` - Adds plugin to list and prints "Registered: [name]"
  - `runPlugins(text)` - Runs each plugin in sequence, passing output of one as input to next. Prints "Running: [name]" before each plugin

---

## 📊 Relationship Diagram

```
          ┌─────────────────────┐
          │   <<interface>>     │
          │     Plugin          │
          │─────────────────────│
          │ + execute(text)     │
          │ + getName()         │
          └─────────────────────┘
               ▲         ▲         ▲
               │         │         │
         (realizes)   (realizes) (realizes)
               │         │         │
        ┌──────┴──┐  ┌───┴────┐  ┌┴──────────┐
        │ Spell   │  │ Word   │  │ Upper    │
        │ Check   │  │ Count  │  │ Case     │
        └─────────┘  └────────┘  └──────────┘

TextEditor (uses Plugin interface, not concrete classes)
```

---

## 🔑 Key Advantages of Realization

| Advantage | Benefit |
|-----------|---------|
| **Extensibility** | Add new plugins without modifying TextEditor |
| **Loose Coupling** | TextEditor depends on interface, not implementations |
| **Polymorphism** | Run any plugin through the same interface |
| **Type Safety** | All plugins must implement required methods |
| **Plugin Architecture** | Easy to add/remove plugins dynamically |

---

## 💡 Key Concepts Covered

- Interface realization/implementation
- Contract enforcement through interfaces
- Polymorphic behavior through interfaces
- Extensibility without modification (Open/Closed Principle)
- Plugin architecture pattern
- Dependency on abstractions, not concrete classes