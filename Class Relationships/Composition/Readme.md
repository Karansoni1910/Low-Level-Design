# 🧩 Composition

**Definition:** Composition is a "part-of" relationship where a parent class contains child objects that cannot exist independently. When the parent is destroyed, all child objects are also destroyed.

---

## 📋 Problem Statement

A **Conversation** composes **Message** objects. Messages are created when `sendMessage(sender, text)` is called. Deleting a conversation deletes all its messages. Messages belong to exactly one conversation and have no meaning outside of it.

---

## ✅ Requirements

### Message Class
- **Fields:** `sender`, `text`, `timestamp`
- **Methods:**
  - `display()` - Prints the message in format "[sender]: text"

### Conversation Class
- **Fields:** `title`, list of `Message` objects
- **Methods:**
  - `sendMessage(sender, text)` - Creates a Message internally and adds it to the list
  - `printHistory()` - Prints conversation title and all messages
  - `delete()` - Clears all messages (they are destroyed with the conversation)
  - `forwardMessage(target, messageIndex)` - ⭐ Challenge: Copy message content into a NEW Message in target conversation

---

## 📊 Relationship Diagram

```
Conversation ○────→ Messages
   (whole)      (parts - owned)
   
When Conversation is deleted:
Messages are destroyed ❌
```

---

## 🔑 Key Differences: Composition vs Aggregation

| Aspect | Composition | Aggregation |
|--------|-------------|-------------|
| **Ownership** | Strong (whole owns parts) | Weak (whole references parts) |
| **Lifecycle** | Parts die with whole | Parts survive whole deletion |
| **Shareability** | Parts exclusive to whole | Parts can be shared |
| **Example** | Conversation owns Messages | Company has Employees |

---

## 💡 Key Concepts Covered

- Strong ownership relationship
- Exclusive object ownership
- Dependent object lifecycle
- Part-of relationships
- Object destruction and cleanup
- Difference between composition and aggregation