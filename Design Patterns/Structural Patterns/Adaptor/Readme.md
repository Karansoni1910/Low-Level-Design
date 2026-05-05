# 🔌 Adapter Pattern

**Definition:** The Adapter Pattern is a structural design pattern that converts the interface of a class into another interface that clients expect. This pattern lets you work with incompatible interfaces by creating an adapter that acts as a bridge between them. The pattern is useful when you want to use a class that doesn't match the interface you need.

---

## 📋 Problem Statement

Implement a **Temperature Converter Adapter**. You have a Thermometer interface that returns temperature in Celsius. A third-party weather sensor library provides readings in Fahrenheit through a different interface. Write an adapter so your application can use the Fahrenheit sensor as if it were a Celsius thermometer.

**Real-World Example:** Legacy system integration, third-party library compatibility, multi-platform support, or converting between different API standards (e.g., converting Celsius/Fahrenheit, different payment gateways, or database adapters).

---

## ✅ Requirements

### Target Interface (Thermometer)
- **getTemperature()** - Returns temperature in Celsius (double)

### Adaptee (FahrenheitSensor)
- **readFahrenheit()** - Returns temperature reading in Fahrenheit (double)
- Incompatible interface with Thermometer

### Adapter (FahrenheitToCelsiusAdapter)
- Implements the Thermometer interface
- Uses FahrenheitSensor internally
- Converts Fahrenheit to Celsius using the formula: (F - 32) × 5/9
- Client code can use the adapter as if it were a normal Thermometer

---

## 🎯 Key Features

- **Interface Translation:** Converts one interface to another seamlessly
- **Code Reusability:** Use existing incompatible code without modification
- **Loose Coupling:** Clients depend on the target interface, not the adapter
- **Backward Compatibility:** Integrate legacy systems with modern code

---

## 💡 Key Concepts Covered

- Interface adaptation and conversion
- Wrapper pattern for interface compatibility
- Bridging incompatible interfaces
- Delegation pattern
- Real-world unit conversion and transformation

---

## 🎯 Common Use Cases

- **Legacy System Integration:** Connecting old and new systems
- **Third-Party Libraries:** Adapting external libraries to your interface
- **Unit Conversion:** Converting between different units (temperature, distance, etc.)
- **Protocol Adapters:** Converting between different communication protocols
- **Database Adapters:** Converting between different database interfaces
- **Payment Gateway Integration:** Adapting different payment provider APIs