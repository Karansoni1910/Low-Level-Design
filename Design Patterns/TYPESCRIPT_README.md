# Design Patterns - TypeScript Implementation

This directory contains TypeScript implementations of classic software design patterns. Each pattern is mirrored from the Java implementations and is fully compilable and executable.

## Patterns Included

### Creational Patterns
1. **Singleton** - Ensures a class has only one instance with a global point of access
2. **Factory** - Creates objects without specifying their exact classes
3. **Abstract Factory** - Creates families of related or dependent objects
4. **Builder** - Constructs complex objects step by step
5. **Prototype** - Creates new objects by cloning existing ones

### Structural Patterns
1. **Adapter** - Converts the interface of one class into another interface expected by clients
2. **Bridge** - Decouples an abstraction from its implementation
3. **Composite** - Composes objects into tree structures for part-whole hierarchies
4. **Decorator** - Attaches additional responsibilities to objects dynamically
5. **Facade** - Provides a simplified interface to a subsystem
6. **Proxy** - Provides a surrogate for another object to control access

## Requirements

- Node.js (v14 or higher)
- TypeScript (v5.0 or higher)

## Setup

1. Install dependencies:
```bash
npm install
```

## Compilation

Compile all TypeScript files:
```bash
npm run build
```

Compile and clean previous builds:
```bash
npm run build:clean
```

## Running Individual Patterns

You can run each pattern individually:

### Creational Patterns
```bash
npm run run:singleton
npm run run:factory
npm run run:abstract-factory
npm run run:builder
npm run run:prototype
```

### Structural Patterns
```bash
npm run run:adaptor
npm run run:bridge
npm run run:composite
npm run run:decorator
npm run run:facade
npm run run:proxy
```

## Compilation Output

All compiled JavaScript files will be generated in the `dist/` directory, maintaining the same folder structure as the source files.

## Manual Compilation and Execution

To manually compile and run a specific pattern:

```bash
# Compile
tsc

# Run a specific pattern (example: Singleton)
node dist/Creational\ Patterns/Singleton/Main.js
```

## File Structure

```
Design Patterns/
├── tsconfig.json
├── package.json
├── README.md
├── Creational Patterns/
│   ├── Singleton/
│   │   ├── Main.java
│   │   └── Main.ts
│   ├── Factory/
│   │   ├── Main.java
│   │   └── Main.ts
│   ├── Abstract Factory/
│   │   ├── Main.java
│   │   └── Main.ts
│   ├── Builder/
│   │   ├── Main.java
│   │   └── Main.ts
│   └── Prototype/
│       ├── Main.java
│       └── Main.ts
└── Structural Patterns/
    ├── Adaptor/
    │   ├── Main.java
    │   └── Main.ts
    ├── Bridge/
    │   ├── Main.java
    │   └── Main.ts
    ├── Composite/
    │   ├── Main.java
    │   └── Main.ts
    ├── Decorator/
    │   ├── Main.java
    │   └── Main.ts
    ├── Facade/
    │   ├── Main.java
    │   └── Main.ts
    └── Proxy/
        ├── Main.java
        └── Main.ts
```

## Notes

- All TypeScript implementations are strict-typed for better development experience
- The implementations closely follow the Java versions while using TypeScript idioms
- Each pattern is self-contained and can be compiled independently
- The `dist/` directory can be safely deleted and regenerated using `npm run build`

## Using Individual Files

If you want to use a specific pattern in your own TypeScript project:

1. Copy the relevant `Main.ts` file or extract the classes/interfaces you need
2. Ensure you have TypeScript configured in your project
3. Import and use the classes/interfaces as needed

Example for using Singleton:
```typescript
// Import or copy the Singleton pattern
class Counter {
    // ... implementation
}

// Usage
const instance1 = Counter.getInstance();
const instance2 = Counter.getInstance();
console.log(instance1 === instance2); // true
```

## TypeScript Version

These implementations use modern TypeScript features and target ES2020. Make sure your `tsconfig.json` is compatible or modify it according to your needs.
