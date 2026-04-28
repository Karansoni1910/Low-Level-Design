# 🏗️ Builder Pattern

**Definition:** The Builder Pattern is a creational design pattern that provides a flexible solution for constructing complex objects. It separates object construction from its representation, allowing you to create different configurations of an object using the same construction process. This pattern is particularly useful when dealing with objects that have many optional parameters.

---

## 📋 Problem Statement

Implement a **Builder for an Email class**. Emails have some required fields (recipient and subject) and many optional fields (cc, bcc, body, priority, attachments). Without the Builder pattern, you'd need telescoping constructors or setters that break immutability.

**Real-World Example:** Email clients, HTTP request builders, SQL query builders, or any complex object with multiple optional configurations.

---

## ✅ Requirements

### Email Class (Immutable)
- **Private constructor** - Takes a Builder object
- **Final fields** - All fields are immutable after construction
- **toString()** - Returns formatted string showing all fields

### Email.Builder Class (Static Inner Class)

| Method/Field | Type | Description |
|--------------|------|-------------|
| **`to`** | Required | Recipient email address (constructor parameter) |
| **`subject`** | Required | Email subject line (constructor parameter) |
| **`cc(String)`** | Optional | Add CC recipient (chainable, can be called multiple times) |
| **`bcc(String)`** | Optional | Add BCC recipient (chainable, can be called multiple times) |
| **`body(String)`** | Optional | Email body content (chainable) |
| **`priority(String)`** | Optional | Email priority (chainable, defaults to "normal") |
| **`attachment(String)`** | Optional | Add attachment (chainable, can be called multiple times) |
| **`build()`** | Method | Constructs and returns the final Email object |

---

## 🎯 Key Features

- **Fluent Interface:** Method chaining for readable code
- **Immutability:** Email objects are immutable after construction
- **Optional Parameters:** Clean handling of multiple optional fields
- **Validation:** Required fields enforced through constructor
- **Flexibility:** Easy to add new optional parameters without breaking existing code

---

## 💡 Key Concepts Covered

- Separation of construction and representation
- Fluent API design with method chaining
- Handling required vs optional parameters
- Immutable object creation
- Static inner class pattern
- Encapsulation of complex construction logic

---

## 🎯 Common Use Cases

- Email/Message builders
- HTTP request/response builders
- Database query builders
- Configuration objects
- Test data builders
- Domain objects with many optional fields

---

## ✅ Expected Output

```
Email{to='alice@example.com', subject='Meeting Tomorrow', cc=[], bcc=[], body='Let's meet at 10am in conference room B.', priority='normal', attachments=[]}

Email{to='bob@example.com', subject='Project Update', cc=[carol@example.com, dave@example.com], bcc=[manager@example.com], body='Attached is the Q4 report.', priority='high', attachments=[q4-report.pdf, summary.xlsx]}
```

---

## 🚀 Advantages

✅ **Readable Code:** Method chaining makes object creation self-documenting  
✅ **Flexibility:** Easy to add new optional parameters  
✅ **Immutability:** Thread-safe, final objects  
✅ **No Telescoping Constructors:** Avoids constructor explosion  
✅ **Validation:** Can validate state before building