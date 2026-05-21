# 🔄 State Pattern

## 📌 Overview

The **State Pattern** is a behavioral design pattern that allows an object to alter its behavior when its internal state changes. The object will appear to change its class, enabling you to encapsulate state-specific behavior in separate state classes.

This pattern is particularly useful when:
- An object's behavior depends on its state and must change at runtime
- Operations have large conditional statements based on the object's state
- You want to eliminate long if-else or switch statements
- State transitions need to be explicit and maintainable

---

## 🎯 Core Concepts

### Components

1. **State Interface** - Defines the interface for state-specific behavior
2. **Concrete States** - Implement behavior specific to each state
3. **Context** - Maintains the current state and delegates requests to the state object

### Key Principles

- ✅ **Encapsulation**: Each state encapsulates its own behavior
- ✅ **Single Responsibility**: Each state class has one responsibility
- ✅ **Open/Closed Principle**: New states can be added without modifying existing code
- ✅ **Reduced Complexity**: Eliminates complex conditional logic

---

## 💡 Practical Example: Document Workflow

### Scenario
We're building a document management system where documents progress through different states in a workflow. Each state has specific rules about what operations are allowed.

### State Transitions

```
Draft ──submit──> Under Review ──approve──> Published
  ↑                    ↓ reject              ↓
  └────────────────────┴──unpublish─────────┘
```

### State Rules

| State | Edit | Submit | Approve | Reject | Unpublish |
|-------|------|--------|---------|--------|-----------|
| **Draft** | ✅ Yes | ✅ Yes | ❌ No | ❌ No | ❌ No |
| **Under Review** | ❌ No | ❌ No | ✅ Yes | ✅ Yes | ❌ No |
| **Published** | ❌ No | ❌ No | ❌ No | ❌ No | ✅ Yes |

---

## 🏗️ Architecture

### Class Diagram

```
┌─────────────────────┐
│  DocumentState      │ (Interface)
│  <<interface>>      │
├─────────────────────┤
│ + edit()            │
│ + submitForReview() │
│ + approve()         │
│ + reject()          │
│ + unpublish()       │
└─────────────────────┘
        ▲
        │ implements
        │
   ┌────┴─────┬────────────┐
   │           │            │
┌──┴──────┐ ┌─┴────────┐ ┌──┴──────────┐
│ Draft   │ │ Under    │ │ Published   │
│ State   │ │ Review   │ │ State       │
│         │ │ State    │ │             │
└─────────┘ └──────────┘ └─────────────┘

┌──────────────────┐
│   Document       │ (Context)
│ (Context)        │
├──────────────────┤
│ - state          │
│ - content        │
├──────────────────┤
│ + edit()         │
│ + setState()     │
│ + submit()       │
│ + approve()      │
│ + reject()       │
│ + unpublish()    │
└──────────────────┘
```

---

## 🔍 Benefits

1. **Simplified Complex Logic** - Eliminates large conditional statements
2. **Improved Maintainability** - State-specific logic is isolated
3. **Easy State Addition** - New states can be added without modifying existing code
4. **Better Code Organization** - Each state handles its own behavior
5. **Runtime Flexibility** - States can be changed dynamically at runtime

---

## ⚠️ Trade-offs

| Pros | Cons |
|------|------|
| ✅ Eliminates complex conditionals | ❌ Creates more classes |
| ✅ Easy to add new states | ❌ May be overkill for simple state machines |
| ✅ Single Responsibility | ❌ Slight performance overhead |
| ✅ Open/Closed Principle | ❌ Requires more upfront design |

---

## 📋 Implementation Steps

1. **Identify States** - Define all possible states the object can be in
2. **Create State Interface** - Define common behavior interface
3. **Implement Concrete States** - Create a class for each state
4. **Implement Context** - Create context class that delegates to states
5. **Add State Transitions** - Define how states transition to each other
6. **Test Transitions** - Verify state transitions work correctly

---

## 🎓 Real-World Applications

- 🎮 **Game Characters** - Different states (idle, walking, running, jumping)
- 🚦 **Traffic Light** - Red → Yellow → Green transitions
- 📱 **Network Connections** - Disconnected → Connecting → Connected → Disconnected
- 💳 **Payment Processing** - Pending → Processing → Completed/Failed
- 📝 **Document Workflows** - Draft → Review → Published (as in our example)
- 🎬 **Media Players** - Playing → Paused → Stopped
- 🔐 **Security Systems** - Armed → Triggered → Disarmed

---

## 🚀 When to Use State Pattern

**Use State Pattern when:**
- Object behavior depends on its state
- State-specific behavior changes at runtime
- You have large conditional statements based on state
- Multiple operations depend on the current state

**Avoid State Pattern when:**
- Object has very few states
- State transitions are simple and rare
- Performance is critical (due to method call overhead)
- Simple if-else logic is more readable

---

## 📖 See Also

- **Strategy Pattern** - Similar structure but different purpose (algorithm selection)
- **Template Method** - Defines skeleton of algorithm with customizable steps
- **Chain of Responsibility** - Passes request along a chain of handlers
- **Builder Pattern** - Constructs complex objects step by step

---

## ✨ Pattern Comparison

| Aspect | State | Strategy |
|--------|-------|----------|
| **Purpose** | Encapsulate state behavior | Encapsulate algorithms |
| **Who Changes** | Object changes itself | Client changes strategy |
| **Transitions** | Between states (implicit) | Between strategies (explicit) |
| **Coupling** | Context couples to states | Client couples to strategies |
| **Use Case** | State workflows | Algorithm alternatives |