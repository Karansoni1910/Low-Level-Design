# Iterator Design Pattern - Playlist Navigation

## Overview
The Iterator pattern is a behavioral design pattern that provides a way to access elements of a collection sequentially without exposing its underlying representation. The pattern allows you to traverse through a collection in different ways without modifying the collection structure.

## Objective
Implement a flexible iteration system for a music playlist that supports both forward and reverse traversal. Create a `ReversePlaylistIterator` that traverses the playlist from the last song to the first, while maintaining the existing forward iteration functionality.

## Problem & Solution

### Problem
- Collections need to be traversed in different ways (forward, reverse, filtered, etc.)
- Adding all traversal logic directly to the collection class violates Single Responsibility Principle
- Different clients may need different iteration orders
- Clients should not need to know the internal structure of collections

### Solution
- Define an Iterator interface that encapsulates iteration logic
- Create separate iterator implementations for different traversal strategies
- Allow the collection to provide multiple iterators without modification
- Clients use a uniform interface to iterate through collections

## Architecture

### Components

#### 1. **Iterator Interface**
Defines the contract for traversing a collection
```
+ hasNext(): boolean
+ next(): Element
```

#### 2. **Concrete Iterators**
- `PlaylistIterator` → Traverses forward from first to last song
- `ReversePlaylistIterator` → Traverses backward from last to first song

#### 3. **Collection: Playlist**
- Stores songs/items
- Provides `iterator()` method to create forward iterator
- Provides `reverseIterator()` method to create reverse iterator

#### 4. **Element: Song**
Represents individual items in the collection

## Implementation Requirements

| Requirement | Description |
|-------------|-------------|
| **Iterator Interface** | Defines `hasNext()` and `next()` methods |
| **PlaylistIterator** | Implements forward traversal (given - do not modify) |
| **ReversePlaylistIterator** | Implements backward traversal from last to first |
| **Playlist Class** | Stores songs, provides iterator() and reverseIterator() |
| **Constraints** | Existing Playlist and forward PlaylistIterator must not be modified |

## Usage Example

```java
Playlist playlist = new Playlist();
playlist.addSong("Shape of You");
playlist.addSong("Bohemian Rhapsody");
playlist.addSong("Blinding Lights");

// Forward iteration
Iterator<String> forward = playlist.iterator();
while (forward.hasNext()) {
    System.out.println(forward.next());  // A, B, C
}

// Reverse iteration
Iterator<String> reverse = playlist.reverseIterator();
while (reverse.hasNext()) {
    System.out.println(reverse.next());  // C, B, A
}
```

## Key Concepts

| Concept | Description |
|---------|-------------|
| **Iterator** | An object that traverses a collection step by step |
| **Collection** | Provides iterators but doesn't control traversal |
| **Separation of Concerns** | Iteration logic separated from collection logic |
| **Multiple Iterators** | Different traversal strategies without modification |
| **Encapsulation** | Internal collection structure remains hidden |
| **Uniform Interface** | All iterators follow the same contract |

## Benefits

✅ **Multiple Traversals** - Same collection, different iteration orders  
✅ **Single Responsibility** - Iterator handles traversal, collection stores data  
✅ **Uniform Interface** - All iterators follow the same contract  
✅ **Extensibility** - Easy to add new iterator types (filtered, sorted, etc.)  
✅ **Decoupling** - Client doesn't need to know collection internal structure  
✅ **No Modification** - Add iterators without changing existing code  
✅ **Consistent Access** - All iterators provide the same hasNext() and next() methods  

## Real-World Applications

- **Database Queries** - Iterate through result sets forward or reverse
- **Collections Framework** - Java Collections, C++ STL iterators
- **Playlist/Media Players** - Play songs forward or backward
- **File Systems** - Navigate directories and files
- **UI Components** - Tree navigation, table scrolling
- **Search Results** - Page navigation through results

## Comparison with Direct Access

| Aspect | Iterator | Direct Access |
|--------|----------|----------------|
| **Abstraction** | Hides internal structure | Exposes structure |
| **Flexibility** | Easy to add new traversals | Difficult to add new traversals |
| **Coupling** | Loosely coupled | Tightly coupled |
| **Performance** | Slight overhead | Direct access |
| **Maintenance** | Easy to maintain | Hard to modify |

## Flow Diagram

```
Client
  ↓
Iterator Interface
  ├→ PlaylistIterator (Forward)
  │  └→ hasNext(), next()
  │
  └→ ReversePlaylistIterator (Backward)
     └→ hasNext(), next()

Playlist Collection
  ├→ addSong()
  ├→ iterator()
  └→ reverseIterator()
```

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| hasNext() | O(1) | O(1) |
| next() | O(1) | O(1) |
| Creating iterator | O(1) | O(1) |
| Iterating n items | O(n) | O(1) |

## Implementation Patterns

### Pattern 1: Index-Based Iterator
- Maintains an index pointer
- Suitable for list-based collections

### Pattern 2: Reference-Based Iterator
- Maintains node references
- Suitable for linked structures

### Pattern 3: Snapshot Iterator
- Creates a copy of data
- Safe from concurrent modifications
- **File System Navigation** - Browse files in different orders
- **Menu Navigation** - Navigate menus forward or backward
- **Undo/Redo Systems** - Iterate through action history
- **Streaming Data** - Process data streams in different sequences
- **Tree Traversal** - DFS, BFS, level-order traversals