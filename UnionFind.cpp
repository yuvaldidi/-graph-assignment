// UnionFind.cpp
// yuvalgaddidi@gmail.com

#include "UnionFind.hpp"

namespace graph {

// Constructor: initializes the union-find structure
UnionFind::UnionFind(int size) {
    this->size = size;
    parent = new int[size];
    rank = new int[size];

    // Initialize each element to be its own parent (disjoint sets)
    for (int i = 0; i < size; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Destructor: frees the memory used by the union-find structure
UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

// Finds the root of the set containing x
int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Unites the sets containing x and y
void UnionFind::unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

} // namespace graph
