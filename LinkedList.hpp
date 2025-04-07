// yuvaldaddidi@gmail.com

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

namespace graph {

/*
    One node in the list - used to store a neighbor.
    Each node has the vertex number, weight, and pointer to the next.
*/
struct Node {
    int vertex;
    int weight;
    Node* next;

    Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
};

/*
    A basic linked list for storing neighbors in the graph.
    Used by the Graph class for each node’s adjacency list.
*/
class LinkedList {
private:
    Node* headNode;

public:
    // Create an empty list
    LinkedList();

    // Copy another list into this one
    LinkedList(const LinkedList& other);

    // Assign this list from another
    LinkedList& operator=(const LinkedList& other);

    // Free the memory
    ~LinkedList();

    // Add a new neighbor to the beginning of the list
    void insert(int vertex, int weight);

    // Remove a neighbor by vertex number
    void remove(int vertex);

    // Check if a neighbor exists
    bool contains(int vertex) const;

    // Print the list (used in graph print)
    void print() const;

    // Count how many neighbors there are
    int size() const;

    // Get pointer to the first node
    Node* head() const;

    // Same as head(), used in comparisons
    Node* getHead() const;

    // Compare two lists (used when comparing graphs)
    bool operator==(const LinkedList& other) const;
};

} // namespace graph

#endif
