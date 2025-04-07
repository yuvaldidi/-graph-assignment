// yuvaldaddidi@gmail.com

#include "Graph.hpp"
#include <iostream>

namespace graph {

// Create the graph with N nodes and an empty list for each one
Graph::Graph(int vertices) : vertices(vertices) {
    adjacencyList = new LinkedList[vertices];
}

// Copy another graph (deep copy)
Graph::Graph(const Graph& other) : vertices(other.vertices) {
    adjacencyList = new LinkedList[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjacencyList[i] = other.adjacencyList[i];
    }
}

// Assign this graph from another one (deep copy)
Graph& Graph::operator=(const Graph& other) {
    if (this == &other) return *this;

    delete[] adjacencyList;

    vertices = other.vertices;
    adjacencyList = new LinkedList[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjacencyList[i] = other.adjacencyList[i];
    }

    return *this;
}

// Clean up the memory when the graph is destroyed
Graph::~Graph() {
    delete[] adjacencyList;
}

// Add an edge between two nodes (undirected)
// Throws if the index is bad or if src == dest
void Graph::addEdge(int src, int dest, int weight) {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        throw std::out_of_range("Index out of range in addEdge");

    if (src == dest)
        throw std::invalid_argument("Cannot add edge to itself");

    adjacencyList[src].insert(dest, weight);
    adjacencyList[dest].insert(src, weight);
}

// Remove the edge between two nodes
// Throws if the edge doesn't exist or index is invalid
void Graph::removeEdge(int src, int dest) {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        throw std::out_of_range("Index out of range in removeEdge");

    if (!adjacencyList[src].contains(dest))
        throw std::invalid_argument("Edge does not exist");

    adjacencyList[src].remove(dest);
    adjacencyList[dest].remove(src);
}

// Check if there's an edge between two nodes
bool Graph::hasEdge(int src, int dest) const {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        throw std::out_of_range("Index out of range in hasEdge");

    return adjacencyList[src].contains(dest);
}

// Return the neighbor list of a node
const LinkedList& Graph::getNeighbors(int vertex) const {
    if (vertex < 0 || vertex >= vertices)
        throw std::out_of_range("Index out of range in getNeighbors");

    return adjacencyList[vertex];
}

// Just return how many nodes we have
int Graph::getSize() const {
    return vertices;
}

// Print the graph: every node and its neighbors
void Graph::print_graph() const {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Node " << i << ": ";
        adjacencyList[i].print();
    }
}

// Compare two graphs (same structure and weights)
bool Graph::operator==(const Graph& other) const {
    if (this->getSize() != other.getSize()) return false;

    for (int i = 0; i < this->getSize(); ++i) {
        const Node* thisNeighbors = this->getNeighbors(i).head();
        const Node* otherNeighbors = other.getNeighbors(i).head();

        while (thisNeighbors && otherNeighbors) {
            if (thisNeighbors->vertex != otherNeighbors->vertex ||
                thisNeighbors->weight != otherNeighbors->weight)
                return false;

            thisNeighbors = thisNeighbors->next;
            otherNeighbors = otherNeighbors->next;
        }

        // One list is longer than the other
        if (thisNeighbors || otherNeighbors) return false;
    }

    return true;
}

} // namespace graph
