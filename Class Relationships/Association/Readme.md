# 🔗 Association

**Definition:** Association represents a relationship between two classes where one class uses or interacts with another class. It can be one-to-one, one-to-many, or many-to-many, and objects can exist independently.

---

## 📋 Problem Statement

Build a course platform where instructors create courses and students enroll in them. This exercise practices unidirectional and one-to-many associations.

---

## ✅ Requirements

### Instructor Class
- **Field:** `name`, list of `Course` objects
- **Method:**
  - `addCourse(course)` - Adds the course and sets the instructor on the course

### Course Class
- **Fields:** `title`, `Instructor` reference, list of `Student` objects
- **Methods:**
  - `setInstructor(instructor)` - Sets the instructor reference
  - `enrollStudent(student)` - Adds student and sets enrolled course on the student

### Student Class
- **Fields:** `name`, `enrolledCourse` reference
- **Methods:**
  - `setEnrolledCourse(course)` - Sets the enrolled course reference
  - `getInstructorName()` - Navigates through course to return instructor's name (or "No instructor" if null)

---

## 📊 Relationship Diagram

```
Instructor ──────→ Course ──────→ Student
  (1)               (many)         (many)
```

---

## 💡 Key Concepts Covered

- One-to-many relationships
- Object navigation through associations
- Bidirectional reference management
- Independent object existence
- Real-world modeling of course enrollment