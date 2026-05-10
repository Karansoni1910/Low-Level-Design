# 🌳 Composite Pattern

**Definition:** The Composite Pattern is a structural design pattern that allows you to compose objects into tree structures to represent part-whole hierarchies. The pattern lets clients treat individual objects and compositions of objects uniformly. It is useful when you want to build tree-like structures where individual elements and groups of elements can be treated the same way.

---

## 📋 Problem Statement

Implement a **Restaurant Menu System** where individual menu items and submenus share a common interface. A MenuItem is a leaf with a name and price. A SubMenu is a composite with a name that contains menu items and other submenus. Both should support displaying their contents and counting total items.

**Real-World Example:** File systems (folders containing files and other folders), organization hierarchies (departments with teams and employees), GUI components (panels containing buttons and other panels), or document structures (pages with sections and paragraphs).

---

## ✅ Requirements

### Component Interface (Menu)
- **display(indent)** - Prints the menu/item with proper indentation
- **getItemCount()** - Returns the total count of items

### Leaf (MenuItem)
- **name** and **price** fields
- **display()** prints the item with name and price
- **getItemCount()** returns 1

### Composite (SubMenu)
- **name** field and collection of child menus
- **display()** prints its name then delegates to all children
- **getItemCount()** sums up counts from all children
- Methods to add/remove child menus
- Supports nested submenus (submenus containing other submenus)

---

## 🎯 Key Features

- **Unified Interface:** Treat both individual items and containers uniformly
- **Tree Structure:** Build hierarchical compositions of any depth
- **Flexible Composition:** Easily add or remove components
- **Recursive Behavior:** Operations propagate through the tree structure
- **Transparent Containers:** Clients don't need to differentiate between leaf and composite objects

---

## 💡 Key Concepts Covered

- Tree structures and hierarchies
- Recursive composition
- Uniform treatment of individual and composite objects
- Part-whole relationships
- Encapsulation of tree navigation
- Dynamic component addition and removal

---

## 🎯 Common Use Cases

- **File Systems:** Directories containing files and subdirectories
- **Organization Hierarchies:** Departments, teams, and employees
- **GUI Frameworks:** Panels, buttons, containers, and nested layouts
- **Document Structure:** Chapters, sections, paragraphs, and text
- **Graphics Systems:** Shapes, groups, and layered drawings
- **Menu Systems:** Categories, subcategories, and menu items
- **DOM Trees:** HTML elements containing other elements