// Graph.hpp
// yuvaldaddidi@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "LinkedList.hpp"

namespace graph {

/*
    Graph class - uses adjacency list (array of linked lists).
    Graph is undirected and can have weights on the edges.
*/
class Graph {
private:
    int vertices;               // number of nodes in the graph
    LinkedList* adjacencyList; // one list per node

public:
    // Create a graph with N nodes (no edges yet)
    Graph(int vertices);

    // Copy another graph into a new one (deep copy)
    Graph(const Graph& other);

    // Replace this graph with another one
    Graph& operator=(const Graph& other);

    // Free the memory when the graph is deleted
    ~Graph();

    // How many nodes are in the graph
    int getSize() const;

    // Get the neighbor list of a node
    // Throws if the index is invalid
    const LinkedList& getNeighbors(int node) const;

    // Add an edge between two nodes (both directions)
    // Throws if index is invalid or same node
    void addEdge(int source, int dest, int weight = 1);

    // Remove the edge between two nodes
    // Throws if the edge doesn't exist or index is bad
    void removeEdge(int source, int dest);

    // Check if there's an edge between two nodes
    // Throws if the index is out of range
    bool hasEdge(int source, int dest) const;

    // Print the graph in a readable way
    void print_graph() const;

    // Compare two graphs (same nodes and edges)
    bool operator==(const Graph& other) const;
};

} // namespace graph

#endif // GRAPH_HPP
