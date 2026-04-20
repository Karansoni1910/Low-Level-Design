# 🔗 Coupling and Cohesion

**Definition:** 
- **Coupling:** The degree to which classes depend on each other. Low coupling means classes are independent; high coupling means they're tightly intertwined.
- **Cohesion:** The degree to which elements within a class belong together. High cohesion means all methods and data serve a single purpose.

**Goal:** Aim for **Low Coupling + High Cohesion** for maintainable, flexible code.

---

## 📋 Problem Statement

You have a `ReportGenerator` class that suffers from **high coupling and low cohesion**:

```java
// ❌ High Coupling + Low Cohesion
class ReportGenerator {
    private Database database;
    private EmailClient emailClient;
    private FileWriter fileWriter;
    private Logger logger;
    
    public void generateAndSendReport() {
        // Tightly coupled to Database
        List<Data> data = database.query("SELECT * FROM data");
        
        // Generates report AND formats it AND sends it
        String report = formatReport(data);
        
        // Tightly coupled to EmailClient
        emailClient.send("admin@example.com", report);
        
        // Also tightly coupled to FileWriter
        fileWriter.write("report.txt", report);
        
        // And also uses Logger
        logger.log("Report generated");
    }
}
```

**Problems:**
- High coupling (depends on Database, EmailClient, FileWriter, Logger)
- Low cohesion (does multiple unrelated tasks)
- Hard to test (must mock 4 dependencies)
- Hard to extend (can't change email without modifying)

Your task: **Reduce coupling and increase cohesion** by separating concerns and using interfaces.

---

## ✅ Requirements

### Create Interfaces (Reduce Coupling)
- `DataSource` interface - Abstract database access
- `ReportFormatter` interface - Abstract report formatting
- `Distributor` interface - Abstract report distribution

### High Cohesion Classes (Single Purpose)
- `ReportGenerator` - Only generates reports
- `EmailDistributor` - Only sends via email
- `FileDistributor` - Only saves to file
- `ConsoleDistributor` - Only prints to console

### Orchestrator
- `ReportService` - Coordinates using injected dependencies

### Test Cases
- Generate report from data
- Distribute via email
- Distribute to file
- Distribute to console
- Easy to add new distributors without modifying existing code

---

## 📊 High vs Low Coupling/Cohesion

### ❌ High Coupling + Low Cohesion
```
ReportGenerator (God Class)
├─ Depends on Database
├─ Depends on EmailClient
├─ Depends on FileWriter
├─ Depends on Logger
└─ Does: Generate, Format, Send, Log

(Tight coupling, mixed responsibilities)
```
**Problems:** Fragile, hard to test, low reusability

### ✅ Low Coupling + High Cohesion
```
ReportGenerator (generates only)
    ↓
ReportService (orchestrator)
├─ Depends on DataSource (interface)
├─ Depends on ReportFormatter (interface)
└─ Depends on Distributor (interface)
    ├─ EmailDistributor (sends email only)
    ├─ FileDistributor (saves file only)
    └─ ConsoleDistributor (prints only)

(Loose coupling via interfaces, focused responsibility)
```
**Benefits:** Flexible, testable, reusable

---

## 🔑 Key Concepts Covered

- **Loose Coupling** - Depend on abstractions, not concrete classes
- **High Cohesion** - Class members are closely related
- **Interface Segregation** - Small, focused interfaces
- **Dependency Injection** - Pass dependencies instead of creating them
- **Flexibility** - Easy to swap implementations
- **Testability** - Mock interfaces, not concrete classes
- **Extensibility** - Add new behaviors without modifying existing code

---

## 💡 Why Coupling and Cohesion Matter

| Issue | Impact |
|-------|--------|
| **High Coupling** | Changes cascade, hard to modify, low reusability |
| **Low Cohesion** | Hard to understand, multiple reasons to change |
| **Mixed responsibilities** | Classes do too many things |
| **Tight concrete dependencies** | Can't replace implementations easily |
| **Testing nightmare** | Must set up many dependencies |

By achieving Low Coupling + High Cohesion:
- ✅ Code is easier to understand
- ✅ Changes are localized
- ✅ Components are reusable
- ✅ Testing is simpler
- ✅ System is flexible and scalable

---

## 📊 Coupling Metrics

### High Coupling ❌
- Class depends on many others
- Concrete class dependencies
- Hard to instantiate for testing
- Changes affect many other classes

### Low Coupling ✅
- Depends on few abstractions
- Interface dependencies
- Easy to mock for testing
- Changes are isolated

---

## 📊 Cohesion Metrics

### Low Cohesion ❌
- Class has many unrelated responsibilities
- Methods don't share data
- Hard to name the class
- Changes have multiple reasons

### High Cohesion ✅
- Class has single, focused responsibility
- Methods work with same data
- Clear class name/purpose
- One reason to change

---

## 🔗 Related Principles

- **Single Responsibility Principle (SRP)** - High cohesion
- **Dependency Inversion Principle (DIP)** - Low coupling via interfaces
- **Interface Segregation Principle (ISP)** - Small, focused interfaces
- **Separation of Concerns** - Divide by responsibility
- **Law of Demeter** - Minimize object dependencies