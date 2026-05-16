# Iterator Design Pattern - Playlist Navigation

## Overview
A behavioral design pattern that provides a way to access elements of a collection sequentially without exposing its underlying representation. The Iterator pattern allows you to traverse through a collection in different ways without modifying the collection structure.

## Objective
Implement a flexible iteration system for a music playlist that supports both forward and reverse traversal. Create a ReversePlaylistIterator that traverses the playlist from the last song to the first, while maintaining the existing forward iteration functionality.

## Problem & Solution

**Problem:**
- Collections need to be traversed in different ways (forward, reverse, filtered, etc.)
- Adding all traversal logic directly to the collection class violates Single Responsibility Principle
- Different clients may need different iteration orders

**Solution:**
- Define an Iterator interface that encapsulates iteration logic
- Create separate iterator implementations for different traversal strategies
- Allow the collection to provide multiple iterators without modification

## Architecture

### Components

#### 1. **Iterator Interface**
Defines the contract for traversing a collection
```
+ hasNext(): boolean
+ next(): Element
+ reset(): void
```

#### 2. **Concrete Iterators**
- `PlaylistIterator` → Traverses forward from first to last song
- `ReversePlaylistIterator` → Traverses backward from last to first song

#### 3. **Collection: `Playlist`**
- Stores songs/items
- Provides `iterator()` method to create forward iterator
- Provides `reverseIterator()` method to create reverse iterator

#### 4. **Element: `Song`**
Represents individual items in the collection

## Implementation Requirements

- **Iterator Interface:** Defines `hasNext()`, `next()`, and `reset()` methods
- **PlaylistIterator:** Implements forward traversal
- **ReversePlaylistIterator:** Implements backward traversal
- **Playlist Class:**
  - Stores songs internally
  - Provides `iterator()` for forward iteration
  - Provides `reverseIterator()` for reverse iteration
- **Constraints:**
  - Existing Playlist and forward PlaylistIterator must not be modified
  - Both iterators work independently without interference

## Usage Example

```
Playlist playlist = new Playlist();
playlist.addSong("Song A");
playlist.addSong("Song B");
playlist.addSong("Song C");

// Forward iteration
Iterator forward = playlist.iterator();
while (forward.hasNext()) {
    System.out.println(forward.next());  // A, B, C
}

// Reverse iteration
Iterator reverse = playlist.reverseIterator();
while (reverse.hasNext()) {
    System.out.println(reverse.next());  // C, B, A
}
```

## Key Concepts

| Concept | Description |
|---------|-------------|
| **Iterator** | An object that traverses a collection step by step |
| **Collection** | Provides iterators but doesn't control traversal |
| **Separation** | Iteration logic separated from collection logic |
| **Multiple Iterators** | Different traversal strategies without modification |
| **Encapsulation** | Internal collection structure remains hidden |

## Benefits

✅ **Multiple Traversals** - Same collection, different iteration orders  
✅ **Single Responsibility** - Iterator handles traversal, collection stores data  
✅ **Uniform Interface** - All iterators follow the same contract  
✅ **Extensibility** - Easy to add new iterator types (filtered, sorted, etc.)  
✅ **Decoupling** - Client doesn't need to know collection internal structure  
✅ **No Modification** - Add iterators without changing existing code

## Real-World Applications

- **Database Queries** - Iterate through result sets forward or reverse
- **File System Navigation** - Browse files in different orders
- **Menu Navigation** - Navigate menus forward or backward
- **Undo/Redo Systems** - Iterate through action history
- **Streaming Data** - Process data streams in different sequences
- **Tree Traversal** - DFS, BFS, level-order traversals