# 🚫 YAGNI - You Aren't Gonna Need It

**Definition:** YAGNI (You Aren't Gonna Need It) is a principle that states you should never code for features, functionality, or complexity that you don't currently need. Building for hypothetical future requirements wastes time, introduces unnecessary code, and makes the system harder to maintain.

---

## 📋 Problem Statement

A developer built a **full validation rules engine** just to check if a password is at least 8 characters long. The system includes:
- `ValidationRule` interface
- `MinLengthRule` class
- `HasUpperCaseRule` class
- `HasDigitRule` class
- `PasswordValidator` class with a validation engine

**All of this for a single requirement:** Check if password length ≥ 8 characters.

Your task: **Strip down to a single class with a single `isValid()` method** that solves the actual problem.

---

## ✅ Requirements

### PasswordValidator Class
- **Method:** `isValid(String password)` - Validates password length

### Validation Logic
1. **Accept** a password string
2. **Return** `true` if password is at least 8 characters, `false` otherwise
3. **Handle** null/empty passwords (return `false`)

### Test Cases
- Input: `"short"` → Output: `false`
- Input: `"longenough"` → Output: `true`
- Input: `"12345678"` → Output: `true`
- Input: `""` → Output: `false`
- Input: `null` → Output: `false`

---

## 📊 Overengineered vs Simple

### ❌ Overengineered (Violating YAGNI)
```
1 Interface (ValidationRule)
    ↓
3 Rule Classes (MinLength, HasUpperCase, HasDigit)
    ↓
PasswordValidator (with validation engine)
    ↓
Just to check: password.length() >= 8
```
**Problems:** 5 files for 1 requirement, added features not needed

### ✅ Simple (Following YAGNI)
```
PasswordValidator
    ↓
isValid(password)
    ├─ Check if null/empty
    ├─ Check length >= 8
    ↓
Result
```
**Benefits:** 1 class, solves exactly what's needed, nothing more

---

## 🔑 Key Concepts Covered

- **Avoid Premature Generalization** - Don't build flexible systems for hypothetical needs
- **YAGNI vs SOLID** - Balance between YAGNI simplicity and SOLID principles
- **Scope Creep Prevention** - Build only what's required now
- **Code Bloat Reduction** - Eliminate unused functionality
- **Maintenance Cost** - Less code = easier to maintain
- **Technical Debt** - Unnecessary complexity becomes technical debt

---

## 💡 Why YAGNI Matters

| Problem | Impact |
|---------|--------|
| **Building for hypothetical needs** | Wasted development time and resources |
| **Over-generalization** | Makes code harder to understand and maintain |
| **Feature bloat** | Introduces complexity that may never be used |
| **Debugging nightmare** | More code = more places for bugs to hide |
| **Maintenance burden** | Future developers must understand unnecessary complexity |

By following YAGNI, we:
- ✅ Build faster (only what's needed)
- ✅ Reduce complexity
- ✅ Minimize maintenance overhead
- ✅ Make better design decisions based on real requirements
- ✅ Refactor when actual new requirements emerge

---

## ⚖️ YAGNI vs DRY vs KISS

| Principle | Focus | Goal |
|-----------|-------|------|
| **YAGNI** | Don't add unnecessary features | Build only what's required |
| **DRY** | Don't repeat code logic | Eliminate duplication |
| **KISS** | Keep solutions simple | Avoid over-engineering |

All three principles work together to create clean, maintainable code.