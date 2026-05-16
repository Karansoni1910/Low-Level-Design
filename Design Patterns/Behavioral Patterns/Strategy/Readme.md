# Strategy Design Pattern - Text Formatter

## Overview
A behavioral design pattern that defines a family of algorithms, encapsulates each one, and makes them interchangeable. The Strategy pattern lets the algorithm vary independently from clients that use it.

## Objective
Build a text formatting system where different strategies format text in different ways. The TextEditor context should allow swapping formatters at runtime, so the same editor can produce uppercase, lowercase, or title case output depending on the active strategy.

## Problem & Solution

**Problem:** 
- Different formatting requirements need to be applied to the same text
- Hardcoding all formatting logic in one class leads to complex, hard-to-maintain code

**Solution:**
- Define an interface for formatting strategies
- Create separate classes for each formatting algorithm
- Allow the context (TextEditor) to swap strategies at runtime

## Architecture

### Components

#### 1. **Strategy Interface: `TextFormatter`**
Defines the contract for all formatting strategies
```
+ format(text: String): String
```

#### 2. **Concrete Strategies**
- `UpperCaseFormatter` → Converts text to UPPERCASE
- `LowerCaseFormatter` → Converts text to lowercase
- `TitleCaseFormatter` → Converts text To Title Case

#### 3. **Context: `TextEditor`**
- Holds a reference to the current strategy
- `setFormatter(formatter)` - Switch strategies at runtime
- `publishText(text)` - Apply the current strategy

## Implementation Requirements

- **Strategy interface:** `TextFormatter` with `format(text)` method that returns a formatted string
- **Concrete strategies:** 
  - `UpperCaseFormatter`
  - `LowerCaseFormatter`
  - `TitleCaseFormatter`
- **Context:** `TextEditor` with:
  - `setFormatter()` to swap strategies
  - `publishText()` to format and print text

## Usage Example

```
TextEditor editor = new TextEditor(new UpperCaseFormatter());
editor.publishText("hello world");  // Output: HELLO WORLD

editor.setFormatter(new LowerCaseFormatter());
editor.publishText("HELLO WORLD");  // Output: hello world

editor.setFormatter(new TitleCaseFormatter());
editor.publishText("hello world");  // Output: Hello World
```

## Key Concepts

| Concept | Description |
|---------|-------------|
| **Strategy** | An algorithm encapsulated as a separate class |
| **Context** | Uses a strategy without knowing its implementation |
| **Interchangeability** | Strategies can be swapped at runtime |
| **Open/Closed** | Open for extension (new formatters), closed for modification |

## Benefits

✅ **Runtime Flexibility** - Change algorithms at runtime without modifying client code  
✅ **Elimination of Conditionals** - Replace if-else chains with polymorphism  
✅ **Easy to Test** - Each strategy can be tested independently  
✅ **Single Responsibility** - Each formatter handles one formatting approach  
✅ **Open/Closed Principle** - Add new formatters without modifying existing code

## Real-World Applications

- **Payment Processing** - Different payment methods (Credit Card, PayPal, Crypto)
- **Sorting Algorithms** - QuickSort, MergeSort, BubbleSort implementations
- **Export Formats** - PDF, Excel, CSV exporters
- **Compression Techniques** - ZIP, GZIP, BZIP2 algorithms
- **Authentication** - Different auth strategies (OAuth, JWT, Basic Auth)