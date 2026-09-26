# Data Structures Overview

What each common data structure is, when to use it, and how they compare. Code for each one is linked in the [main README](../README.md).

## Array

A collection of items stored next to each other in memory. Each item has an index.

- Example: `[10, 20, 30, 40]`
- Use when the number of elements is known in advance and you need fast access by index.
- Use cases: student marks, image pixels, any ordered data of fixed size.
- Pros: access by index is O(1).
- Cons: inserting or deleting in the middle is O(n), because later elements must shift.

## Hash map (hash table)

Stores key–value pairs. A hash function turns each key into a bucket index.

- Example: `{ "name": "Ali", "age": 20 }`
- Use when you need to find data quickly by key and order does not matter.
- Use cases: user ID → user details, word frequency counting, caching.
- Pros: search, insert and delete are O(1) on average.
- Cons: no ordering, uses more memory, and O(n) in the worst case when many keys collide.

## Singly linked list

A chain of nodes. Each node stores its data and a pointer to the next node.

- Example: `10 → 20 → 30 → NULL`
- Nodes are not stored next to each other, and the list can grow or shrink.
- Use when you insert and delete often and do not need random access.
- Use cases: music playlist, basic undo history.
- Pros: dynamic size; insert/delete at the head is O(1). Elsewhere it is O(1) only if you already hold the node before the position, because each node only knows the next one.
- Cons: access by position is O(n).

## Doubly linked list

Like a singly linked list, but each node also points to the previous node.

- Example: `NULL ← 10 ⇄ 20 ⇄ 30 → NULL`
- Use when you need to move both forward and backward.
- Use cases: browser back/forward navigation, text editors.
- Pros: easy backward traversal; any node you hold can be removed in O(1), because it knows the node before it.
- Cons: extra memory for the previous pointer.

## Stack

LIFO: last in, first out. Think of a stack of plates.

- Operations: push (add to top), pop (remove from top).
- Use for reversing things and for anything that nests, such as function calls.
- Use cases: undo/redo, expression evaluation, the program call stack.
- Pros: simple, and every operation is O(1).
- Cons: only the top element is accessible.

## Queue

FIFO: first in, first out. Think of people standing in a line.

- Operations: enqueue (add at the rear), dequeue (remove from the front).
- Use when order matters and items should be processed fairly.
- Use cases: CPU scheduling, printer jobs, breadth-first search.
- Pros: fair, ordered processing with O(1) operations.
- Cons: no random access.

## Binary search tree (BST)

A tree where every value in a node's left subtree is smaller than the node, and every value in its right subtree is larger. Checking only each parent and its direct children is not enough.

```
      50
     /  \
   30    70
```

- Use when you want data kept sorted and searchable.
- Use cases: databases, auto-complete.
- Pros: search, insert and delete are O(log n) when the tree is balanced.
- Cons: degrades to O(n) when unbalanced, for example after inserting sorted data.

## Tree (general)

A hierarchy with a root and parent–child relationships.

- Example: the folder structure on a computer.
- Use when the data is naturally hierarchical.
- Use cases: file systems, organisation charts, the HTML DOM.
- Pros: represents hierarchy directly.
- Cons: more complex than linear structures.

## Graph

A set of nodes (vertices) connected by edges.

- Example: a social network.
- Types: directed or undirected, weighted or unweighted.
- Use when relationships are complex and there can be many paths between items.
- Use cases: maps and routing, social connections, recommendation systems.
- Pros: very flexible.
- Cons: harder to implement and traverse.

## Summary

| Data structure | Best used when |
|---|---|
| Array | Fast access by index is needed |
| Hash map | Fast lookup by key is needed |
| Linked list | Insertions and deletions are frequent |
| Stack | Undo, recursion, nested structure |
| Queue | Scheduling, processing in order |
| BST | Sorted data with fast search |
| Tree | Data is hierarchical |
| Graph | Data is a network of relationships |

## Comparisons

### Array vs linked list vs hash map

| Feature | Array | Linked list | Hash map |
|---|---|---|---|
| Storage | Contiguous memory | Separate nodes | Key–value pairs in buckets |
| Access | By index | Sequential only | By key |
| Ordering | Ordered | Ordered | Unordered |

| Operation | Array | Linked list | Hash map |
|---|---|---|---|
| Access | O(1) | O(n) | O(1) average |
| Insert | O(n) | O(1)* | O(1) average |
| Delete | O(n) | O(1)* | O(1) average |
| Search | O(n) | O(n) | O(1) average |

\* Once you already have the position (for a singly linked list, the node before it). Finding the position is O(n).

- **Array:** size is fixed or predictable and you need index access. Example: marks, matrices, image data.
- **Linked list:** frequent insertions and deletions, order matters, random access does not. Example: playlists, memory management.
- **Hash map:** fast lookup by key is the priority. Example: user ID → profile, caches.

### Singly vs doubly linked list

| Feature | Singly | Doubly |
|---|---|---|
| Pointers | Next only | Next and previous |
| Traversal | One direction | Both directions |
| Memory | Less | More |
| Operations | Slightly faster | Slightly slower |

Use a singly linked list when memory matters and you never walk backwards. Use a doubly linked list when you need backward movement, such as browser navigation.

### Stack vs queue

| Feature | Stack | Queue |
|---|---|---|
| Rule | LIFO | FIFO |
| Insert | Push | Enqueue |
| Remove | Pop | Dequeue |
| Access | Top only | Front only |
| Order of removal | Reversed | Preserved |

- Stack: undo/redo, function calls, expression evaluation.
- Queue: CPU scheduling, BFS, print jobs.

### Tree vs binary search tree

| Feature | Tree | BST |
|---|---|---|
| Ordering | No rule | Left < root < right |
| Searching | Slow (visit every node) | Fast (one path from the root) |
| Structure | Hierarchy | Sorted hierarchy |

Use a general tree for hierarchical data such as folders or the DOM. Use a BST when you need sorted data with fast search.

### Tree vs graph

| Feature | Tree | Graph |
|---|---|---|
| Cycles | No | Allowed |
| Parents per node | One | Any number |
| Structure | Hierarchy | Network |
| Complexity | Simpler | More complex |

- Tree: file systems, organisation charts.
- Graph: social networks, maps and routing, recommendations.

### Linear vs non-linear

| Category | Examples | Shape |
|---|---|---|
| Linear | Array, linked list, stack, queue | Data in a sequence |
| Non-linear | Tree, graph | Data in a hierarchy or network |
