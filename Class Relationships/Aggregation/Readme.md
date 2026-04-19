# 📦 Aggregation

**Definition:** Aggregation is a "has-a" relationship where a parent class contains references to child objects, but the child objects can exist independently. Deleting the parent doesn't destroy the children.

---

## 📋 Problem Statement

Build a company system where employees can belong to multiple teams. Dissolving a team doesn't remove the employees. This exercise reinforces that aggregation parts survive the deletion of the whole and can be shared.

---

## ✅ Requirements

### Employee Class
- **Fields:** `name`, `role`, list of `Team` objects
- **Methods:**
  - `addTeam(team)` - Adds team to employee's team list
  - `removeTeam(team)` - Removes team from employee's team list
  - `getTeamNames()` - Returns list of team names the employee belongs to

### Team Class
- **Fields:** `name`, list of `Employee` objects
- **Methods:**
  - `addMember(employee)` - Adds employee and registers team on the employee
  - `dissolve()` - Clears member list without destroying employees

### Company Class
- **Fields:** `name`, list of `Employee` objects, list of `Team` objects
- **Methods:**
  - `addEmployee(employee)` - Adds employee to company
  - `addTeam(team)` - Adds team to company
  - `dissolveTeam(team)` - Dissolves the team and removes it from the company

---

## 📊 Relationship Diagram

```
        Company
       /       \
      ↓         ↓
  Employees   Teams
      ↑         ↓
      └────○────┘
    (Shared Employees)
```

---

## 💡 Key Concepts Covered

- Weak ownership relationship
- Shared objects across containers
- Independent object lifecycle
- Many-to-many relationships
- Proper cleanup without object destruction