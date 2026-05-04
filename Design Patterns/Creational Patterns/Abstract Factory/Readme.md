# 🎨 Abstract Factory Pattern

**Definition:** The Abstract Factory Pattern is a creational design pattern that provides an interface for creating families of related or dependent objects without specifying their concrete classes. This pattern ensures that the objects created are compatible and belong to the same family, making it ideal for systems that need to work with multiple related product families.

---

## 📋 Problem Statement

Implement a **theming system for a UI framework** where each theme (Light and Dark) must produce compatible pairs of UI components. Each theme produces two related products: a `ThemeColor` and a `ThemeFont`. The abstract factory ensures that colors and fonts from the same theme are always used together, preventing mismatched visual themes.

**Real-World Example:** UI frameworks with multiple themes (Light/Dark/HighContrast), cross-platform applications supporting different operating system families (Windows/macOS/Linux), or furniture factories producing coordinated chair and table sets.

---

## ✅ Requirements

### Interfaces
| Interface | Method | Purpose |
|-----------|--------|---------|
| **ThemeColor** | `apply()` | Applies the color theme to the UI |
| **ThemeFont** | `render()` | Renders the font for the theme |
| **ThemeFactory** | `createColor()` | Creates a ThemeColor instance |
| **ThemeFactory** | `createFont()` | Creates a ThemeFont instance |

### Concrete Products

#### Light Theme
- **LightColor** - Prints: `"Applying light color: #FFFFFF background, #000000 text"`
- **LightFont** - Prints: `"Rendering light theme font: Arial, 14px"`

#### Dark Theme
- **DarkColor** - Prints: `"Applying dark color: #1E1E1E background, #FFFFFF text"`
- **DarkFont** - Prints: `"Rendering dark theme font: Consolas, 14px"`

### Concrete Factories
- **LightThemeFactory** - Creates Light-themed color and font components
- **DarkThemeFactory** - Creates Dark-themed color and font components

### Client
- **ThemeClient** - Uses a factory to create and apply theme components together

---

## 🎯 Key Features

- **Family Consistency:** Ensures colors and fonts from the same theme are used together
- **Loose Coupling:** Client code depends on abstractions, not concrete implementations
- **Easy Theme Switching:** Add new themes by implementing new factory classes
- **Extensibility:** New theme families can be added without modifying existing code

---

## 💡 Key Concepts Covered

- Abstract factory interface pattern
- Family of related objects creation
- Encapsulation of object creation logic
- Promoting consistency across related objects
- Dependency inversion principle

---

## 🔄 When to Use

✅ Multiple families of related products (Light/Dark themes)
✅ Need to ensure product families are used together
✅ Want to hide concrete product creation from clients
✅ System must be independent of how products are created
✅ Frequently need to add new product families