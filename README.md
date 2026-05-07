# 📚 Low-Level-Design

> A comprehensive repository containing the fundamentals of Low-Level Design (LLD) concepts frequently asked in technical interviews.

---

## 🎯 Objective

Master OOP principles and design patterns through hands-on examples and problem-solving exercises.

---

## 📂 Topics Covered

### 🏛️ OOP Fundamentals

Core object-oriented programming concepts that form the foundation of software design.

| Concept | Description | Focus |
|---------|-------------|-------|
| **[Classes & Objects](./OOP-fundamentals/Classes%20%26%20Objects/)** | 🏗️ Blueprints and instances for creating real-world models | Creation & Instantiation |
| **[Encapsulation](./OOP-fundamentals/Encapsulation/)** | 🔐 Data hiding and controlled access | Data Protection |
| **[Abstraction](./OOP-fundamentals/Abstraction/)** | 🎭 Hiding complexity and exposing essentials | Interface Design |
| **[Inheritance](./OOP-fundamentals/Inheritance/)** | 👨‍👩‍👧‍👦 Reusing code through parent-child relationships | Code Reusability |
| **[Enums](./OOP-fundamentals/Enums/)** | 🚦 Type-safe constant definitions | Type Safety |
| **[Interfaces](./OOP-fundamentals/Interfaces/)** | 📞 Contracts and loose coupling | Contract Definition |

### 🔀 Class Relationships

Understanding how classes interact and relate to each other in real-world systems.

| Type | Description | Characteristic |
|------|-------------|-----------------|
| **[Association](./Class%20Relationships/Association/)** | 🔗 Objects use or interact with each other | Independent lifespans |
| **[Aggregation](./Class%20Relationships/Aggregation/)** | 📦 Weak "has-a" relationship | Children survive parent deletion |
| **[Composition](./Class%20Relationships/Composition/)** | 🧩 Strong "part-of" relationship | Parts destroyed with whole |
| **[Dependency Injection](./Class%20Relationships/Depedency/)** | 💉 Injecting dependencies from external sources | Loose coupling & flexibility |
| **[Realization](./Class%20Relationships/Realization/)** | 🔌 Implementing interface contracts | Polymorphic behavior |

### 🎨 Design Patterns

Proven solutions to common software design problems that promote reusability and maintainability.

#### Creational Patterns
Patterns that deal with object creation mechanisms, trying to create objects in a manner suitable to the situation.

| Pattern | Description | Focus |
|---------|-------------|-------|
| **[Abstract Factory](./Design%20Patterns/Creational%20Patterns/Abstract%20Factory/)** | 🎨 Creates families of related objects consistently | Family consistency & product compatibility |
| **[Singleton](./Design%20Patterns/Creational%20Patterns/Singleton/)** | 🔒 Ensures one instance exists globally | Single instance & global access |
| **[Factory Method](./Design%20Patterns/Creational%20Patterns/Factory/)** | 🏭 Creates objects without specifying exact classes | Abstraction & loose coupling |
| **[Builder](./Design%20Patterns/Creational%20Patterns/Builder/)** | 🏗️ Constructs complex objects step by step | Flexible object creation with optional parameters |
| **[Prototype](./Design%20Patterns/Creational%20Patterns/Prototype/)** | 🎭 Creates objects by copying existing prototypes | Deep copying & independent object instances |

#### Structural Patterns
Patterns that deal with object composition, creating relationships between entities to form larger structures while keeping these structures flexible and efficient.

| Pattern | Description | Focus |
|---------|-------------|-------|
| **[Adapter](./Design%20Patterns/Structural%20Patterns/Adaptor/)** | 🔌 Converts incompatible interfaces for compatibility | Interface translation & legacy system integration |
| **[Facade](./Design%20Patterns/Structural%20Patterns/Facade/)** | 🎭 Provides unified interface to complex subsystems | Simplification & subsystem coordination |

### 🎨 Design Principles

Best practices and principles that guide professional software design.

| Principle | Description | Focus |
|-----------|-------------|-------|
| **[DRY](./Design%20Principles/DRY/)** | 🔁 Don't Repeat Yourself | Eliminate code duplication |
| **[KISS](./Design%20Principles/KISS/)** | 🎯 Keep It Simple, Stupid | Simplicity over complexity |
| **[YAGNI](./Design%20Principles/YAGNI/)** | 🚫 You Aren't Gonna Need It | Build only what's required |
| **[Law of Demeter](./Design%20Principles/Law%20of%20Demeter/)** | 📞 Tell, Don't Ask | Avoid reaching into nested objects |
| **[Separation of Concerns](./Design%20Principles/Separation%20of%20Concerns/)** | 🎯 SoC | Divide system by concerns |
| **[Coupling and Cohesion](./Design%20Principles/Coupling%20and%20Cohesion/)** | 🔗 Low Coupling, High Cohesion | Loose dependencies, focused responsibility |

### 🏗️ SOLID Principles

Five principles that help developers create more understandable, flexible, and maintainable software.

| Principle | Description | Focus |
|-----------|-------------|-------|
| **[Single Responsibility Principle](./SOLID%20principles/Single%20Responsibility%20Principle/)** | 📋 SRP | One class, one reason to change |
| **[Open-Closed Principle](./SOLID%20principles/Open-Closed%20Principle/)** | 📖 OCP | Open for extension, closed for modification |
| **[Liskov Substitution Principle](./SOLID%20principles/Liskov%20Substitution%20Principle/)** | 🔄 LSP | Subclasses properly substitute base classes |
| **[Interface Segregation Principle](./SOLID%20principles/Interface%20Segregation%20Principle/)** | 🧩 ISP | Clients should depend only on methods they use |
| **[Dependency Inversion Principle](./SOLID%20principles/Dependency%20Inversion%20Principle/)** | 🔌 DIP | Depend on abstractions, not concrete implementations |

---

## 🚀 Getting Started

1. Navigate to any concept folder
2. Read the README to understand the problem
3. Review the implementation examples
4. Practice implementing the solutions yourself

---

## 💡 Why LLD Matters

- ✅ Foundation for building scalable applications
- ✅ Essential for system design interviews
- ✅ Improves code maintainability and reusability
- ✅ Helps you write cleaner, more professional code

---

Happy Learning! 🎓