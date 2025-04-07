Graph Algorithms Project

This project is part of a university assignment that required implementing a graph using an adjacency list
and several common graph algorithms — all without using the STL.

The code is written in C++ and uses only manually implemented data structures like linked lists, queues,
priority queues, and union-find.


Project Files:

The project is split into different files to keep it organized:

- The `Graph` class handles the main logic of the graph.
- The `LinkedList` class is used inside the graph to store neighbors.
- `Algorithms` has the actual graph algorithms like BFS, DFS, etc.
- There are also small classes like `Queue`, `PriorityQueue`, and `UnionFind` that are used in the algorithms.
- `main.cpp` is a demo file to show how everything works.
- `test.cpp` contains unit tests for the different functions.
- `Makefile` helps compile and run everything.

How to Run

To compile and run the main demo:
```bash
make Main
```

To run all tests:
```bash
make test
```

To check for memory leaks:
```bash
make valgrind
```

To clean all compiled files:
```bash
make clean
```
