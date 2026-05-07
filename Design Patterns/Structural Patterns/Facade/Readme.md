# 🎭 Facade Pattern

**Definition:** The Facade Pattern is a structural design pattern that provides a unified, simplified interface to a set of interfaces in a subsystem. It hides the complexity of the subsystem and provides a single entry point for client code. The pattern is useful when you want to decouple client code from complex subsystems.

---

## 📋 Problem Statement

Implement a **Smart Home Facade** that controls multiple subsystems (lights, thermostat, and security system). The facade should provide simple `leaveHome()` and `arriveHome()` methods that coordinate all three subsystems together, hiding the complexity of managing individual systems.

**Real-World Example:** Smart home automation, music player systems controlling multiple components, e-commerce order processing that coordinates inventory, payment, and shipping, or software frameworks that simplify complex operations.

---

## ✅ Requirements

### Subsystems (Complex Dependencies)
- **SmartLightsSystem** - Controls lights (on/off)
- **Thermostat** - Controls temperature and mode
- **SecuritySystem** - Arms and disarms security

### Facade (SmartHomeFacade)
- **leaveHome()** - Turns off lights, sets thermostat to eco mode (18°C), arms security system
- **arriveHome()** - Turns on lights, sets thermostat to comfort mode (22°C), disarms security system
- **Coordinates all subsystems** - Single method calls perform multiple operations
- **Each subsystem prints its actions** - Console output showing all operations

---

## 🎯 Key Features

- **Simplified Interface:** Reduces complexity by providing simple methods instead of exposing all subsystems
- **Unified Control:** Coordinate multiple subsystems through single method calls
- **Decoupling:** Client code doesn't need to know about individual subsystems
- **Maintainability:** Changes to subsystems don't affect client code
- **Workflow Automation:** Sequences of operations handled transparently

---

## 💡 Key Concepts Covered

- Providing unified interfaces to complex subsystems
- Reducing client-subsystem coupling
- Workflow coordination and automation
- Encapsulation of subsystem interactions
- Simplification of complex operations

---

## 🎯 Common Use Cases

- **Smart Home Systems:** Coordinating lights, temperature, security, entertainment
- **E-commerce Platforms:** Order processing involving inventory, payment, shipping, notifications
- **Media Players:** Controlling multiple audio/visual components
- **Software Frameworks:** Libraries providing high-level APIs for common tasks
- **API Gateways:** Aggregating multiple backend services into unified endpoints
- **Application Initialization:** Coordinating setup of multiple system components