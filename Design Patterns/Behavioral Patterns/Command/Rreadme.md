# Command Design Pattern - Restaurant Order System

## Overview
The Command pattern is a behavioral design pattern that encapsulates a request as an object, allowing parameterization of clients with different requests, queuing of requests, and logging of requests. It also provides support for undoable operations.

## Objective
Build a restaurant order system where a waiter (invoker) takes orders and can cancel them. A kitchen (receiver) prepares and cancels dishes. The system should support command queuing, batch execution, and undo functionality.

## Problem & Solution

### Problem
- Need to decouple the object that invokes an operation from the one that performs it
- Want to queue requests, log requests, and support undoable operations
- Multiple commands need to be executed in sequence

### Solution
- Encapsulate each request (order) as an object with execute and undo methods
- Create command objects that store the receiver and action parameters
- Allow the invoker to queue and execute commands without knowing their details

## Architecture

### Components

#### 1. **Command Interface**
Defines the contract for all commands
```
+ execute(): void
+ undo(): void
```

#### 2. **Concrete Commands**
- `PlaceOrderCommand` → Executes: prepareDish() | Undo: cancelDish()
- `CancelOrderCommand` → Executes: cancelDish() | Undo: prepareDish()

#### 3. **Receiver: Kitchen**
The object that performs the actual work
```
+ prepareDish(dish: String): void
+ cancelDish(dish: String): void
```

#### 4. **Invoker: Waiter**
Manages command execution and history
```
+ takeOrder(command: Command): void
+ submitOrders(): void
+ undoLast(): void
```

## Implementation Requirements

| Requirement | Description |
|-------------|-------------|
| **OrderCommand Interface** | Defines execute() and undo() methods |
| **Kitchen Receiver** | prepareDish(dish) and cancelDish(dish) methods |
| **PlaceOrderCommand** | execute() calls prepareDish, undo() calls cancelDish |
| **CancelOrderCommand** | execute() calls cancelDish, undo() calls prepareDish |
| **Waiter Invoker** | Maintains pending queue and execution history |

## Usage Example

```java
Kitchen kitchen = new Kitchen();
Waiter waiter = new Waiter();

// Queue orders
waiter.takeOrder(new PlaceOrderCommand(kitchen, "Pasta"));
waiter.takeOrder(new PlaceOrderCommand(kitchen, "Pizza"));

// Execute all queued orders
waiter.submitOrders();  // Output: Preparing: Pasta, Preparing: Pizza

// Undo last operation
waiter.undoLast();      // Output: Cancelling: Pizza
```

## Key Concepts

| Concept | Description |
|---------|-------------|
| **Command Object** | Encapsulates a request with all parameters |
| **Invoker** | Executes commands without knowing their details |
| **Receiver** | Performs the actual work |
| **Queue** | Stores commands for batch execution |
| **History** | Maintains executed commands for undo |
| **Undo/Redo** | Reversible operations through undo method |

## Benefits

✅ **Decoupling** - Invoker doesn't know about receiver implementation  
✅ **Queuing** - Commands can be queued for later execution  
✅ **Logging** - Commands can be logged and replayed  
✅ **Undo/Redo** - Reversible operations with undo support  
✅ **Extensibility** - Easy to add new commands without modifying existing code  
✅ **Macro Commands** - Combine multiple commands into one  

## Real-World Applications

- **Text Editors** - Undo/Redo functionality
- **Restaurant Systems** - Order management and cancellation
- **Remote Controls** - Button commands
- **Transaction Management** - Command logging and replay
- **Task Schedulers** - Queued task execution
- **GUI Buttons** - Button click commands

## Flow Diagram

```
Client → Waiter (Invoker) → Command → Kitchen (Receiver)
                ↓ (queues)
            Pending Queue
                ↓
            submitOrders()
                ↓
            History Stack
                ↓
            undoLast()
```

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| takeOrder | O(1) | O(1) |
| submitOrders | O(n) | O(n) |
| undoLast | O(1) | O(1) |
| Memory for n commands | - | O(n) |
