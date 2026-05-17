# Observer Design Pattern - Weather Station Monitoring

## Overview
A behavioral design pattern that defines a one-to-many dependency between objects so that when one object (subject) changes state, all its dependents (observers) are notified automatically. The Observer pattern is also known as Publish-Subscribe pattern and enables loose coupling between components.

## Objective
Implement a weather station system that broadcasts temperature, humidity, and pressure readings to multiple display components. When weather measurements change, all registered observers should be automatically updated without the subject knowing details about the observers.

## Problem & Solution

**Problem:**
- Multiple display components need to be updated when weather data changes
- Adding display logic directly to WeatherStation creates tight coupling
- Adding new display types requires modifying the subject class
- It's hard to dynamically add or remove displays at runtime

**Solution:**
- Define an Observer interface that subject calls when state changes
- Maintain a list of observers in the subject
- Allow observers to register/unregister dynamically
- Subject notifies all observers without knowing their details

## Architecture

### Components

#### 1. **Observer Interface**
Defines how objects get notified of state changes
```
+ update(subject: Subject): void
```

#### 2. **Subject: WeatherStation**
- Maintains list of observers
- Provides `registerObserver()` and `removeObserver()` methods
- Calls `notifyObservers()` when state changes
- Provides getters for temperature, humidity, pressure

#### 3. **Concrete Observers**
- `CurrentConditionsDisplay` → Shows latest measurement
- `StatisticsDisplay` → Tracks and averages all temperatures

## Implementation Requirements

- **Observer Interface:** Defines `update(station)` method
- **WeatherStation Class:**
  - Manages list of observers
  - Implements register, remove, and notify operations
  - Stores temperature, humidity, and pressure values
- **Display Classes:**
  - Implement WeatherObserver interface
  - Update themselves when notified
- **Constraints:**
  - Observers should not know about each other
  - Subject should not depend on specific observer types
  - Observers can be added/removed at runtime

## Usage Example

```
WeatherStation station = new WeatherStation();
CurrentConditionsDisplay current = new CurrentConditionsDisplay();
StatisticsDisplay stats = new StatisticsDisplay();

station.registerObserver(current);
station.registerObserver(stats);

// Both observers automatically updated
station.setMeasurements(25.0, 65.0, 1013.0);
// Output:
// Current Conditions -> Temp: 25.0, Humidity: 65%, Pressure: 1013.0 hPa
// Statistics -> Avg Temperature: 25.0

station.setMeasurements(28.0, 70.0, 1012.0);
// Output:
// Current Conditions -> Temp: 28.0, Humidity: 70%, Pressure: 1012.0 hPa
// Statistics -> Avg Temperature: 26.5
```

## Key Concepts

| Concept | Description |
|---------|-------------|
| **Subject** | The object whose state changes and notifies observers |
| **Observer** | Objects that receive and respond to notifications |
| **One-to-Many** | Single subject notifies multiple observers |
| **Loose Coupling** | Subject and observers depend only on interfaces |
| **Push vs Pull** | Subject can push data or observers can pull it |
| **Dynamic Subscription** | Observers can register/unregister at runtime |

## Benefits

✅ **Loose Coupling** - Subject and observers are decoupled through interface  
✅ **Dynamic Relationships** - Observers can be added/removed at runtime  
✅ **Broadcast Communication** - Subject notifies all observers automatically  
✅ **Single Responsibility** - Subject manages state, observers manage display  
✅ **Open/Closed Principle** - Easy to add new observers without modifying subject  
✅ **Distributed Event Handling** - Multiple handlers for same event

## Real-World Applications

- **Event Systems** - GUI frameworks (button clicks, window events)
- **Message Brokers** - Publish-subscribe messaging systems
- **Real-time Dashboards** - Multiple panels updating from single data source
- **Stock Market** - Subscribers notified of price changes
- **Model-View Patterns** - MVC/MVVM where views observe model changes
- **Social Media** - Followers notified when user posts new content
- **IoT Sensors** - Multiple systems monitoring same sensor data