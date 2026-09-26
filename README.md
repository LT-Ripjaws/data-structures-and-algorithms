<h1 align="center"> Data-structures & Algorithms </h1>

<p align="center">
  <img src="https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExY2tsM2VyY2VlOHdtMTJwYTIxaWw4eGpnaTk1YWxsNnNqZmxlZnpqMSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/5WAdRevloGjuw/giphy.gif" alt="Intro" width="800" height="400" />
</p>

A collection of problems and implementations I've practiced while learning **Data Structures and Algorithms (DSA)** during my days in AIUB.

Everything is written in C++. Each file is a standalone program with a `main` that runs a small example, and the comment at the top of each file explains the idea and its time complexity. Many of the programs started as lab tasks from the Data Structures and Algorithms courses at AIUB.

For a plain-language overview of when to use each data structure, see [notes/data-structures-overview.md](notes/data-structures-overview.md).

## Running a program

Any C++17 compiler works.

## Contents

### 1. Arrays

| Program | What it does |
|---|---|
| [array-reverse-order.cpp](01-arrays/array-reverse-order.cpp) | Print an array forwards and backwards |
| [array-operations.cpp](01-arrays/array-operations.cpp) | Sum, max/min, search, count odd/even, insert and delete at a position |
| [count-even-odd.cpp](01-arrays/count-even-odd.cpp) | Count even and odd numbers |
| [remove-duplicates.cpp](01-arrays/remove-duplicates.cpp) | Remove duplicate values in place |
| [merge-arrays.cpp](01-arrays/merge-arrays.cpp) | Merge two arrays and print in reverse |
| [matrix-operations.cpp](01-arrays/matrix-operations.cpp) | Matrix addition, subtraction, multiplication and transpose |

### 2. Strings

| Program | What it does |
|---|---|
| [palindrome-and-reverse.cpp](02-strings/palindrome-and-reverse.cpp) | Two-pointer reverse and palindrome check |
| [sort-letters-and-digits.cpp](02-strings/sort-letters-and-digits.cpp) | Sort letters and digits separately inside a word |
| [string-encoding.cpp](02-strings/string-encoding.cpp) | Shift every k-th character to encode a string |

### 3. Pointers

| Program | What it does |
|---|---|
| [pointer-basics.cpp](03-pointers/pointer-basics.cpp) | Addresses, dereferencing, arrays as pointers |
| [pointers-and-functions.cpp](03-pointers/pointers-and-functions.cpp) | Swap through pointers, arrays as parameters, `void*` |

### 4. Recursion and backtracking

| Program | What it does |
|---|---|
| [factorial-and-fibonacci.cpp](04-recursion/factorial-and-fibonacci.cpp) | Factorial, naive Fibonacci, memoised Fibonacci |
| [tower-of-hanoi.cpp](04-recursion/tower-of-hanoi.cpp) | Tower of Hanoi, 2^n − 1 moves |
| [permutations-and-subsets.cpp](04-recursion/permutations-and-subsets.cpp) | Generate all permutations and subsets |

### 5. Linked lists

| Program | What it does |
|---|---|
| [singly-linked-list.cpp](05-linked-lists/singly-linked-list.cpp) | Insert, delete, search, reverse |
| [doubly-linked-list.cpp](05-linked-lists/doubly-linked-list.cpp) | Insert and delete at both ends, forward and backward traversal |

### 6. Stacks

| Program | What it does |
|---|---|
| [stack-array.cpp](06-stacks/stack-array.cpp) | Stack on a fixed array with overflow/underflow checks |
| [stack-linked-list.cpp](06-stacks/stack-linked-list.cpp) | Stack on a linked list |
| [balanced-parentheses.cpp](06-stacks/balanced-parentheses.cpp) | Check that `()`, `[]` and `{}` are balanced |
| [infix-to-postfix.cpp](06-stacks/infix-to-postfix.cpp) | Convert infix to postfix and evaluate it |

### 7. Queues

| Program | What it does |
|---|---|
| [queue-palindrome.cpp](07-queues/queue-palindrome.cpp) | Array queue used to check palindromes |
| [circular-queue.cpp](07-queues/circular-queue.cpp) | Circular queue that reuses freed slots |
| [queue-linked-list.cpp](07-queues/queue-linked-list.cpp) | Queue on a linked list |

### 8. Hashing

| Program | What it does |
|---|---|
| [hash-table-chaining.cpp](08-hashing/hash-table-chaining.cpp) | Hash table with separate chaining, used for word counts |

### 9. Trees and heaps

| Program | What it does |
|---|---|
| [binary-search-tree.cpp](09-trees/binary-search-tree.cpp) | Insert, search, delete, height, in/pre/post/level-order traversal |
| [min-heap.cpp](09-trees/min-heap.cpp) | Array-based min-heap (priority queue) |

### 10. Graphs

| Program | What it does |
|---|---|
| [bfs-dfs.cpp](10-graphs/bfs-dfs.cpp) | Breadth-first and depth-first search |
| [dijkstra.cpp](10-graphs/dijkstra.cpp) | Single-source shortest paths with a priority queue |
| [prim-mst.cpp](10-graphs/prim-mst.cpp) | Minimum spanning tree, Prim's algorithm |
| [kruskal-mst.cpp](10-graphs/kruskal-mst.cpp) | Minimum spanning tree, Kruskal's algorithm with union-find |
| [topological-sort.cpp](10-graphs/topological-sort.cpp) | Order tasks with dependencies, detect cycles |

### 11. Searching

| Program | What it does |
|---|---|
| [linear-search.cpp](11-searching/linear-search.cpp) | Check every element |
| [binary-search.cpp](11-searching/binary-search.cpp) | Iterative, recursive and lower-bound binary search |

### 12. Sorting

| Program | What it does |
|---|---|
| [bubble-sort.cpp](12-sorting/bubble-sort.cpp) | Swap adjacent pairs, stop early when sorted |
| [selection-sort.cpp](12-sorting/selection-sort.cpp) | Select the minimum each pass |
| [insertion-sort.cpp](12-sorting/insertion-sort.cpp) | Insert each element into the sorted part |
| [merge-sort.cpp](12-sorting/merge-sort.cpp) | Divide, sort halves, merge |
| [quick-sort.cpp](12-sorting/quick-sort.cpp) | Partition around a pivot |
| [heap-sort.cpp](12-sorting/heap-sort.cpp) | Build a max-heap, extract repeatedly |
| [counting-sort.cpp](12-sorting/counting-sort.cpp) | Count occurrences, no comparisons |

### 13. Greedy algorithms

| Program | What it does |
|---|---|
| [fractional-knapsack.cpp](13-greedy/fractional-knapsack.cpp) | Take items by best profit per unit weight |
| [activity-selection.cpp](13-greedy/activity-selection.cpp) | Most non-overlapping activities |

### 14. Dynamic programming

| Program | What it does |
|---|---|
| [longest-common-subsequence.cpp](14-dynamic-programming/longest-common-subsequence.cpp) | LCS length and the subsequence itself |
| [knapsack-0-1.cpp](14-dynamic-programming/knapsack-0-1.cpp) | 0/1 knapsack with the chosen items |
| [matrix-chain-multiplication.cpp](14-dynamic-programming/matrix-chain-multiplication.cpp) | Cheapest order to multiply a chain of matrices |
| [coin-change.cpp](14-dynamic-programming/coin-change.cpp) | Fewest coins and number of ways |

## Complexity cheat sheet

### Sorting

| Algorithm | Best | Average | Worst | Extra space | Stable |
|---|---|---|---|---|---|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) avg, O(n) worst | No |
| Heap | O(n log n) | O(n log n) | O(n log n) | O(1) | No |
| Counting | O(n + k) | O(n + k) | O(n + k) | O(n + k) | Yes |

### Data structures (average case)

| Structure | Access | Search | Insert | Delete |
|---|---|---|---|---|
| Array | O(1) | O(n) | O(n) | O(n) |
| Linked list | O(n) | O(n) | O(1)* | O(1)* |
| Stack / queue | Top/front only | O(n) | O(1) | O(1) |
| Hash table | — | O(1) | O(1) | O(1) |
| BST (balanced) | O(log n) | O(log n) | O(log n) | O(log n) |
| Binary heap | Min/max O(1) | O(n) | O(log n) | O(log n) |

\* At a known position (for example, the head).

### Graph algorithms

| Algorithm | Time |
|---|---|
| BFS / DFS | O(V + E) with an adjacency list, O(V²) with a matrix |
| Dijkstra (binary heap) | O((V + E) log V) |
| Prim (matrix) | O(V²) |
| Kruskal | O(E log E) |
| Topological sort | O(V + E) |
