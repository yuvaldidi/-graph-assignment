// yuvalgaddidi@gmail.com

#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace graph;

int main() {
    // Create graph and add edges
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);

    // Print original graph
    std::cout << "Original Graph:\n";
    g.print_graph();

    // Run BFS
    Graph bfsTree = Algorithms::bfs(g, 0);
    std::cout << "\nBFS Tree:\n";
    bfsTree.print_graph();

    // Run DFS
    Graph dfsTree = Algorithms::dfs(g, 0);
    std::cout << "\nDFS Tree:\n";
    dfsTree.print_graph();

    // Run Dijkstra
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    std::cout << "\nDijkstra Tree:\n";
    dijkstraTree.print_graph();

    // Run Prim
    Graph primTree = Algorithms::prim(g);
    std::cout << "\nPrim MST:\n";
    primTree.print_graph();

    // Run Kruskal
    Graph kruskalTree = Algorithms::kruskal(g);
    std::cout << "\nKruskal MST:\n";
    kruskalTree.print_graph();

    return 0;
}
