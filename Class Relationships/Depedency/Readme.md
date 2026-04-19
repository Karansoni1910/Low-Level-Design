# 💉 Dependency Injection

**Definition:** Dependency Injection is a design pattern where a class receives its dependencies from external sources rather than creating them internally. This promotes loose coupling and makes code more testable and flexible.

---

## 📋 Problem Statement

Build a file conversion system where a **FileConverter** class depends on **FileReader**, **FormatParser**, and **FileWriter** objects. Instead of creating these dependencies internally, they are injected through method parameters.

---

## ✅ Requirements

### FileReader Class
- **Method:** `read(filePath)` - Reads file content and returns it as a string

### FormatParser Class
- **Method:** `parse(content, targetFormat)` - Converts content to the target format and returns it

### FileWriter Class
- **Method:** `write(filePath, content)` - Writes content to a file

### FileConverter Class
- **Method:** `convert(sourcePath, targetPath, targetFormat, reader, parser, writer)`
  - Takes all dependencies as parameters (dependency injection)
  - Uses reader to read the source file
  - Uses parser to convert the content
  - Uses writer to write to the target file
  - Prints each step for verification

---

## 📊 Relationship Diagram

```
FileConverter
    ↓ (depends on)
    ├── FileReader (injected)
    ├── FormatParser (injected)
    └── FileWriter (injected)
```

---

## 🔑 Key Advantages

| Advantage | Benefit |
|-----------|---------|
| **Loose Coupling** | Classes don't depend on concrete implementations |
| **Testability** | Easy to mock dependencies for unit testing |
| **Flexibility** | Swap implementations without changing FileConverter |
| **Reusability** | FileConverter works with any reader/parser/writer |
| **Maintainability** | Changes to dependencies don't affect FileConverter |

---

## 💡 Key Concepts Covered

- Dependency Injection pattern
- Loose coupling between classes
- Method parameter injection
- Separation of concerns
- Testability and flexibility
- Inversion of Control (IoC)