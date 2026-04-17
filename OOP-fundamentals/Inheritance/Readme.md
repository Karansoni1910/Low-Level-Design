# 👨‍👩‍👧‍👦 Inheritance

**Definition:** Inheritance is a mechanism that allows a class to inherit properties and methods from another class, enabling code reusability and establishing a hierarchical relationship between classes.

---

## 📋 Problem Statement

Build a bank account system using inheritance. The base **BankAccount** class has common fields and methods for deposits and withdrawals. Specialized account types have different withdrawal rules.

---

## ✅ Requirements

### Base BankAccount Class
- **Protected Fields:** `ownerName`, `accountNumber`, `balance`
- **Methods:**
  - `deposit(amount)` - Adds to balance if amount is positive
  - `withdraw(amount)` - Subtracts from balance if funds sufficient, returns true/false
  - `displayAccount()` - Prints "ownerName (accountNumber) | Balance: $balance"

### SavingsAccount (extends BankAccount)
- **Additional Field:** `interestRate`
- **Overridden Method:**
  - `withdraw(amount)` - Enforces minimum balance of $100 (withdrawal fails if balance would drop below $100)
- **New Method:**
  - `applyInterest()` - Increases balance by `balance × interestRate / 100`

### CheckingAccount (extends BankAccount)
- **Additional Field:** `overdraftLimit`
- **Overridden Method:**
  - `withdraw(amount)` - Allows withdrawals up to `balance + overdraftLimit`

### Key Feature
- `displayAccount()` works correctly for all account types without modification

---

## 📊 Class Hierarchy

```
          BankAccount
         /           \
   SavingsAccount   CheckingAccount
   (Min Balance)    (Overdraft)
```

---

## 💡 Key Concepts Covered

- Parent and child class relationships
- Method overriding and polymorphism
- Protected fields for controlled inheritance
- Specialization through subclasses
- Code reusability across account types
