# 🌉 Bridge Pattern

> Decouple abstraction from implementation so that the two can vary independently.

---

## 🎯 Problem Statement

You are building a **messaging system** where messages come in different types (TextMessage, UrgentMessage) and can be sent through different channels (EmailSender, SmsSender). 

**The Challenge:** Without proper design, you'd create combinatorial explosion of classes:
- TextMessageEmail, TextMessageSms
- UrgentMessageEmail, UrgentMessageSms
- And more combinations as new message types or channels are added! 💥

The **Bridge Pattern** solves this by separating **abstraction** (message types) from **implementation** (sending mechanisms), allowing them to vary independently.

---

## 💡 What is the Bridge Pattern?

The Bridge Pattern is a **structural pattern** that decouples an abstraction from its implementation by placing them in separate class hierarchies. This allows changes to the abstraction and implementation independently without affecting each other.

### Core Idea
Instead of creating one class hierarchy mixing both concerns, create:
1. **Abstraction hierarchy** - Different message types
2. **Implementation hierarchy** - Different sending mechanisms
3. Bridge them together with a reference!

---

## 🏗️ Key Components

| Component | Role | Example |
|-----------|------|---------|
| **Implementor** | Interface for implementation classes | `MessageSender` |
| **ConcreteImplementor** | Actual implementation | `EmailSender`, `SmsSender` |
| **Abstraction** | Abstract class with reference to implementor | `Message` |
| **RefinedAbstraction** | Extended abstraction with specific behavior | `TextMessage`, `UrgentMessage` |

---

## 📋 Requirements

### Implementor
```
MessageSender interface with sendMessage(content: String)
```

### ConcreteImplementors
- **EmailSender** - prints "Email: ..."
- **SmsSender** - prints "SMS: ..."

### Abstraction
- **Message** - Abstract class with reference to MessageSender and abstract send() method

### RefinedAbstractions
- **TextMessage** - sends content as-is
- **UrgentMessage** - prefixes content with "[URGENT] "

---

## ✅ When to Use Bridge Pattern

- 🔀 You want to avoid permanent binding between abstraction and implementation
- 📦 You want to share implementations among multiple objects
- 🚀 Changes in implementation shouldn't affect clients
- 🎭 You have multiple dimensions of variation (message types × channels)
- 🔗 You want to reduce class explosion from inheritance hierarchies

---

## 🌍 Real-World Examples

| Domain | Scenario |
|--------|----------|
| **Drawing Apps** | Shape abstraction (Circle, Rectangle) × Renderer (SVG, Canvas) |
| **Database Drivers** | Database abstraction × Different DB implementations (MySQL, PostgreSQL) |
| **UI Frameworks** | Button abstraction × Platform implementation (Windows, Mac, Linux) |
| **Logging Systems** | Logger abstraction × Output destinations (File, Console, Network) |

---

## ⚡ Advantages & Disadvantages

### ✨ Advantages
- 📊 **Decoupling** - Separates abstraction from implementation
- 🎯 **Open/Closed Principle** - Open for extension, closed for modification
- 🔄 **Flexibility** - Change implementations at runtime
- 📈 **Scalability** - Add new message types or channels independently
- ♻️ **Reusability** - Share implementations across abstractions

### ⚠️ Disadvantages
- 🎭 **Complexity** - More classes and interfaces to manage
- 📚 **Learning Curve** - Harder to understand initially
- 💾 **Memory Overhead** - Additional indirection through abstraction

---

## 🎓 Key Takeaway

**Bridge Pattern** ≈ **Composition over Inheritance**

Use Bridge when you have two independent dimensions of variation to prevent creating an exponential number of classes.