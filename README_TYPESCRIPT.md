# Low-Level Design - TypeScript Implementations

Complete TypeScript implementations of software design concepts including OOP fundamentals, Design Principles, Design Patterns, Class Relationships, and SOLID Principles. All files are fully compilable and ready for production use.

## 📂 Project Structure

```
Low-Level-Design/
├── tsconfig.json                          # Root TypeScript configuration
├── package.json                           # NPM dependencies and scripts
├── README.md                              # Main documentation
│
├── Class Relationships/                   # 5 TypeScript implementations
│   ├── Aggregation/Main.ts               # Weak "has-a" relationship
│   ├── Association/Main.ts               # One-to-many relationship
│   ├── Composition/Main.ts               # Strong "has-a" relationship
│   ├── Depedency/Main.ts                # Loose coupling between classes
│   └── Realization/Main.ts              # Interface implementation
│
├── Design Patterns/                       # 11 TypeScript implementations
│   ├── Creational Patterns/
│   │   ├── Singleton/Main.ts            # Single instance guarantee
│   │   ├── Factory/Main.ts              # Object creation without specifying classes
│   │   ├── Abstract Factory/Main.ts     # Family of related objects
│   │   ├── Builder/Main.ts              # Complex object construction
│   │   └── Prototype/Main.ts            # Object cloning
│   └── Structural Patterns/
│       ├── Adapter/Main.ts              # Interface conversion
│       ├── Bridge/Main.ts               # Abstraction from implementation
│       ├── Composite/Main.ts            # Tree structures
│       ├── Decorator/Main.ts            # Dynamic responsibility addition
│       ├── Facade/Main.ts               # Simplified subsystem interface
│       └── Proxy/Main.ts                # Access control
│
├── Design Principles/                     # 6 TypeScript implementations
│   ├── Coupling and Cohesion/Main.ts    # Low coupling, high cohesion
│   ├── DRY/Main.ts                      # Don't Repeat Yourself
│   ├── KISS/Main.ts                     # Keep It Simple
│   ├── Law of Demeter/Main.ts           # Don't talk to strangers
│   ├── Separation of Concerns/Main.ts   # Single responsibility per class
│   └── YAGNI/Main.ts                    # You Aren't Gonna Need It
│
├── OOP-fundamentals/                      # 6 TypeScript implementations
│   ├── Abstraction/Main.ts              # Hide implementation details
│   ├── Classes & Objects/Main.ts        # Blueprint and instances
│   ├── Encapsulation/Main.ts            # Data hiding and bundling
│   ├── Enums/Main.ts                    # Fixed constant sets
│   ├── Inheritance/Main.ts              # Parent-child relationships
│   └── Interfaces/Main.ts               # Contracts and implementations
│
└── SOLID principles/                      # 5 TypeScript implementations
    ├── Single Responsibility Principle/Main.ts   # One reason to change
    ├── Open-Closed Principle/Main.ts             # Open for extension, closed for modification
    ├── Liskov Substitution Principle/Main.ts     # Substitutability of derived classes
    ├── Interface Segregation Principle/Main.ts   # Client-specific interfaces
    └── Dependency Inversion Principle/Main.ts    # Depend on abstractions
```

## 🚀 Quick Start

### Prerequisites

- Node.js (v14 or higher)
- TypeScript (v5.0 or higher)

### Installation

1. Navigate to the project root:
```bash
cd Low-Level-Design
```

2. Install dependencies:
```bash
npm install
```

### Compilation

Compile all TypeScript files to JavaScript:

```bash
npm run build
```

Compile and clean previous builds:

```bash
npm run build:clean
```

Watch for file changes and recompile automatically:

```bash
npm run build:watch
```

## 📖 What's Included

### Class Relationships (5 files)
Learn different types of relationships between classes:
- **Aggregation**: Weak "has-a" relationship (Employee ←→ Team)
- **Association**: One-to-many relationships (Instructor → Course → Student)
- **Composition**: Strong "has-a" relationship (Conversation contains Message)
- **Dependency**: Loose coupling between classes (FileConverter uses dependencies)
- **Realization**: Interface implementation (Plugin interface realized by concrete plugins)

### Design Patterns (11 files)

#### Creational Patterns (5)
- **Singleton**: Ensures only one instance exists globally
- **Factory**: Creates objects without specifying exact classes
- **Abstract Factory**: Creates families of related objects
- **Builder**: Constructs complex objects step by step
- **Prototype**: Creates objects by cloning existing ones

#### Structural Patterns (6)
- **Adapter**: Converts incompatible interfaces to work together
- **Bridge**: Separates abstraction from implementation
- **Composite**: Composes objects into tree structures
- **Decorator**: Adds responsibilities dynamically
- **Facade**: Provides simplified interface to complex subsystems
- **Proxy**: Controls access to another object

### Design Principles (6 files)
Fundamental principles for good software design:
- **Coupling and Cohesion**: Low coupling, high cohesion
- **DRY**: Don't Repeat Yourself - eliminate duplication
- **KISS**: Keep It Simple, Stupid
- **Law of Demeter**: Don't talk to strangers
- **Separation of Concerns**: Each class has single responsibility
- **YAGNI**: You Aren't Gonna Need It

### OOP Fundamentals (6 files)
Core object-oriented programming concepts:
- **Abstraction**: Hide implementation details
- **Classes & Objects**: Blueprints and instances
- **Encapsulation**: Bundle data with methods and hide internals
- **Enums**: Fixed sets of constants
- **Inheritance**: Parent-child class relationships
- **Interfaces**: Contracts and specifications

### SOLID Principles (5 files)
Five principles for scalable, maintainable code:
- **SRP**: Single Responsibility Principle
- **OCP**: Open-Closed Principle
- **LSP**: Liskov Substitution Principle
- **ISP**: Interface Segregation Principle
- **DIP**: Dependency Inversion Principle

## 🎯 How to Use Individual Files

### Option 1: Copy individual files
Extract a single TypeScript file and use it in your project:

```typescript
// Copy from: Design Patterns/Creational Patterns/Singleton/Main.ts
class Counter {
    private count: number = 0;
    private static instance: Counter;

    private constructor() {}

    public static getInstance(): Counter {
        if (!Counter.instance) {
            Counter.instance = new Counter();
        }
        return Counter.instance;
    }
}
```

### Option 2: Compile and run specific patterns
After building:

```bash
npm run build
node dist/Design\ Patterns/Creational\ Patterns/Singleton/Main.js
```

### Option 3: Use in your TypeScript project
Import and use the classes directly:

```typescript
import { Singleton } from './Design Patterns/Creational Patterns/Singleton/Main';
```

## 🔧 Configuration

### TypeScript Compiler Options

The project uses strict TypeScript with the following settings:
- `target`: ES2020
- `strict`: true (strict null checks, strict property initialization, etc.)
- `module`: commonjs
- `moduleResolution`: node
- `esModuleInterop`: true

You can modify `tsconfig.json` to adjust compilation settings for your needs.

## 📝 File Naming

All TypeScript files follow this naming convention:
- **File extension**: `.ts`
- **Main entry points**: `Main.ts` in each folder
- **Compiled output**: `dist/` directory (JavaScript files)

## 🎓 Learning Path

Recommended order for learning:

1. **Start with OOP Fundamentals** (6 files)
   - Classes & Objects
   - Encapsulation
   - Abstraction
   - Inheritance
   - Interfaces
   - Enums

2. **Then Class Relationships** (5 files)
   - Association
   - Composition
   - Aggregation
   - Dependency
   - Realization

3. **Learn Design Principles** (6 files)
   - KISS
   - DRY
   - YAGNI
   - Coupling and Cohesion
   - Law of Demeter
   - Separation of Concerns

4. **Study SOLID Principles** (5 files)
   - Single Responsibility Principle
   - Open-Closed Principle
   - Liskov Substitution Principle
   - Interface Segregation Principle
   - Dependency Inversion Principle

5. **Explore Design Patterns** (11 files)
   - Start with Creational Patterns
   - Then move to Structural Patterns

## 📚 Code Examples

### Example 1: Singleton Pattern
```typescript
const instance1 = Counter.getInstance();
const instance2 = Counter.getInstance();
console.log(instance1 === instance2); // true
```

### Example 2: Factory Pattern
```typescript
const creator = new CircleCreator();
creator.describe(); // Prints circle information
```

### Example 3: Decorator Pattern
```typescript
const pizza = new OliveDecorator(
    new CheeseDecorator(new PlainPizza())
);
console.log(pizza.getDescription()); // Plain pizza, cheese, olives
console.log(pizza.getCost()); // 5.00 + 1.50 + 2.00
```

## ⚙️ Build Output

After running `npm run build`, compiled JavaScript files appear in the `dist/` directory, maintaining the same folder structure:

```
dist/
├── Class Relationships/
├── Design Patterns/
├── Design Principles/
├── OOP-fundamentals/
└── SOLID principles/
```

Delete the `dist/` folder anytime and rebuild with `npm run build`.

## 🤝 Integration

These implementations are:
- ✅ Fully typed with TypeScript
- ✅ Compilable with `tsc` command
- ✅ Production-ready code
- ✅ Educational and reference-friendly
- ✅ Ready for Node.js execution
- ✅ Framework-agnostic (works with React, Angular, Vue, etc.)

## 📄 License

MIT

## 📞 Notes

- All implementations follow TypeScript best practices
- Code is well-commented with clear explanations
- Each file is self-contained and can be compiled independently
- Perfect for learning, reference, or production use
- Covers both conceptual understanding and practical implementation

## 🔄 Updates and Maintenance

To keep the project up-to-date:
1. Update TypeScript: `npm install --save-dev typescript@latest`
2. Rebuild: `npm run build`
3. Review any type changes or deprecations

---

For questions or suggestions about these implementations, refer to the individual README files in each category folder or review the inline code comments.
