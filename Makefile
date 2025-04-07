# Email: yuvaldaddidi@gmail.com

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Object files for running the main demo
OBJS = main.o Graph.o Algorithms.o LinkedList.o Queue.o PriorityQueue.o UnionFind.o

# Object files for running tests (test.cpp replaces main)
TEST_OBJS = test.o Graph.o Algorithms.o LinkedList.o Queue.o PriorityQueue.o UnionFind.o

# === Run the main program (demo)
Main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o graph_exec $(OBJS)
	./graph_exec

# === Run unit tests with doctest
test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o test_exec $(TEST_OBJS)
	./test_exec

# If doctest.h changes, recompile test.o
test.o: doctest.h

# === Run valgrind to check for memory leaks (on main)
valgrind: graph_exec
	valgrind --leak-check=full ./graph_exec

# === Clean all built files
clean:
	rm -f *.o graph_exec test_exec
