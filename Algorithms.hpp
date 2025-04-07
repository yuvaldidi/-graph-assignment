// Email: yuvalgaddidi@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

namespace graph {

// A class containing basic graph algorithms
class Algorithms {
public:
    // Breadth-First Search (BFS)
    static Graph bfs(const Graph& g, int start);

    // Depth-First Search (DFS)
    static Graph dfs(const Graph& g, int start);

    // Dijkstra's algorithm for shortest paths
    static Graph dijkstra(const Graph& g, int start);

    // Prim's algorithm for minimum spanning tree
    static Graph prim(const Graph& g);

    // Kruskal's algorithm for minimum spanning tree
    static Graph kruskal(const Graph& g);
};

} // namespace graph

#endif // ALGORITHMS_HPP
