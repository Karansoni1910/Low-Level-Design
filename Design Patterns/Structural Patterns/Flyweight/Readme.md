# 🪶 Flyweight Pattern

**Definition:** The Flyweight Pattern is a structural design pattern that optimizes memory usage by sharing common data between similar objects. Instead of each object storing its own copy of data, the pattern separates **intrinsic state** (shared, immutable data) from **extrinsic state** (variable, context-specific data) and uses a factory to reuse objects.

---

## 📋 Problem Statement

You are building a **word processor** where documents contain thousands of characters. Each character needs styling information like font family, size, bold, and italic properties. **The Challenge:** If each character object stores its own styling data, memory usage explodes! 💥

The **Flyweight Pattern** solves this by recognizing that many characters share the same styling. Instead of creating duplicate style objects, we cache and reuse them through a factory.

---

## 💡 What is the Flyweight Pattern?

The Flyweight Pattern uses object sharing to efficiently support large numbers of fine-grained objects by sharing common state. It separates:

1. **Intrinsic State** - Shared, immutable data (fontFamily, fontSize, bold, italic)
2. **Extrinsic State** - Context-specific data (line, column, character position)

### Core Idea
Instead of each character object storing everything, the factory maintains a cache of reusable style objects. Multiple characters reference the same style object, drastically reducing memory consumption.

---

## 🏗️ Key Components

| Component | Role | Example |
|-----------|------|---------|
| **Flyweight** | Interface defining operations that depend on extrinsic state | `FontStyle` |
| **ConcreteFlyweight** | Implements flyweight, stores intrinsic state | `ConcreteFontStyle` |
| **FlyweightFactory** | Creates and manages flyweight pool, ensures sharing | `FontStyleFactory` |
| **Context** | Contains extrinsic state and references flyweight | Character position (line, column) |

---

## 📋 Requirements

### Flyweight Interface
```
FontStyle interface with format(line: number, column: number, character: string)
```

### ConcreteFlyweight
- **ConcreteFontStyle** - Stores intrinsic state:
  - `fontFamily` (String)
  - `fontSize` (number)
  - `bold` (boolean)
  - `italic` (boolean)

### FlyweightFactory
- **FontStyleFactory** - Manages flyweight pool:
  - `getFontStyle(fontFamily, fontSize, bold, italic)` - Returns cached or new style
  - `getStyleCount()` - Returns number of unique styles in cache

### Client Code
- Creates multiple characters sharing styles
- Demonstrates that identical style combinations return the same object instance
- Prints style information showing line, column, and character

---

## ✅ When to Use Flyweight Pattern

- 🎭 Application creates many similar fine-grained objects
- 💾 Memory usage is a concern (thousands of similar objects)
- 🔄 Object's state can be divided into intrinsic and extrinsic parts
- 📦 Objects can be immutable or mostly immutable
- 🎯 Many objects can share the same state
- ⚙️ Performance optimization needed for object creation

---

## 🌍 Real-World Examples

| Domain | Scenario |
|--------|----------|
| **Text Editors** | Character objects sharing font/style information (Word, VS Code) |
| **Game Development** | Particle systems sharing sprite and material data |
| **Web Browsers** | DOM nodes sharing common style properties |
| **String Interning** | JVM caching identical string literals to save memory |
| **Database Connection Pools** | Reusing database connections across requests |
| **Sprite Caching** | Video game graphics sharing sprite objects |

---

## ⚡ Advantages & Disadvantages

### ✨ Advantages
- 💾 **Memory Optimization** - Drastically reduces memory usage for similar objects
- ⚡ **Performance** - Faster object creation through reuse (no repeated allocations)
- 🎯 **Scalability** - Supports millions of objects efficiently
- 🔒 **Shared State** - Centralized management of common data
- 🎭 **Transparent Sharing** - Clients unaware of sharing mechanism

### ⚠️ Disadvantages
- 🔀 **Complexity** - Separating intrinsic/extrinsic state is tricky
- 📚 **Learning Curve** - Concept harder to understand and implement
- 🧵 **Thread Safety** - Factory cache needs proper synchronization in multithreaded environments
- 🔍 **Debugging** - Shared state makes debugging more difficult
- 💥 **CPU Trade-off** - May increase CPU usage if objects are looked up frequently

---

## 🎓 Key Takeaway

**Flyweight Pattern** ≈ **Object Pooling + Intrinsic/Extrinsic State Separation**

Use Flyweight when you have a large number of similar objects and memory becomes a bottleneck. Share immutable intrinsic state and pass variable extrinsic state as parameters.