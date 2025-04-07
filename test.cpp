// yuvaldaddidi@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

/*
    Checks if two linked lists contain the same vertices.
    Doesn't care about order. Used for comparing graphs.
*/
bool listsEqual(const LinkedList& a, const LinkedList& b) {
    Node* p1 = a.getHead();
    while (p1 != nullptr) {
        if (!b.contains(p1->vertex)) return false;
        p1 = p1->next;
    }

    Node* p2 = b.getHead();
    while (p2 != nullptr) {
        if (!a.contains(p2->vertex)) return false;
        p2 = p2->next;
    }

    return true;
}

/*
    Compares two graphs by comparing the neighbor list of each node.
*/
bool graphsEqual(const Graph& g1, const Graph& g2) {
    if (g1.getSize() != g2.getSize()) return false;
    for (int i = 0; i < g1.getSize(); ++i) {
        if (!listsEqual(g1.getNeighbors(i), g2.getNeighbors(i))) return false;
    }
    return true;
}

TEST_CASE("Basic graph functions") {
    Graph g(5);

    SUBCASE("Add and check edge") {
        g.addEdge(0, 1, 3);
        g.addEdge(1, 2);
        CHECK(g.hasEdge(0, 1));
        CHECK(g.hasEdge(1, 2));
    }

    SUBCASE("Remove edge") {
        g.addEdge(0, 1);
        g.removeEdge(0, 1);
        CHECK_FALSE(g.hasEdge(0, 1));
    }

    SUBCASE("Graph size") {
        CHECK(g.getSize() == 5);
    }

    SUBCASE("Neighbors list") {
        g.addEdge(0, 4);
        const LinkedList& neighbors = g.getNeighbors(0);
        CHECK(neighbors.contains(4));
    }
}

TEST_CASE("Copy and assignment of graph") {
    Graph g1(3);
    g1.addEdge(0, 1, 2);

    Graph g2 = g1; // Copy constructor
    CHECK(graphsEqual(g1, g2));

    Graph g3(3);
    g3 = g1; // Assignment operator
    CHECK(graphsEqual(g1, g3));
}

/*
    Build a BFS tree that we expect from a sample graph.
*/
Graph createExpectedBFSTree() {
    Graph bfs(5);
    bfs.addEdge(0, 1, 2);
    bfs.addEdge(0, 2, 4);
    bfs.addEdge(1, 3, 7);
    bfs.addEdge(2, 4, 3);
    return bfs;
}

/*
    Build a DFS tree that we expect from a sample graph.
*/
Graph createExpectedDFSTree() {
    Graph dfs(5);
    dfs.addEdge(0, 2, 4);
    dfs.addEdge(2, 1, 1);
    dfs.addEdge(1, 3, 7);
    dfs.addEdge(2, 4, 3);
    return dfs;
}

TEST_CASE("Graph algorithms") {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);

    SUBCASE("BFS works") {
        Graph bfsTree = Algorithms::bfs(g, 0);
        Graph expected = createExpectedBFSTree();
        CHECK(graphsEqual(bfsTree, expected));
    }

    SUBCASE("DFS works") {
        Graph dfsTree = Algorithms::dfs(g, 0);
        Graph expected = createExpectedDFSTree();
        CHECK(graphsEqual(dfsTree, expected));
    }

    SUBCASE("Dijkstra runs") {
        Graph dijkstraTree = Algorithms::dijkstra(g, 0);
        CHECK(dijkstraTree.getSize() == 5); // just checking it runs
    }

    SUBCASE("Prim runs") {
        Graph primTree = Algorithms::prim(g);
        CHECK(primTree.getSize() == 5);
    }

    SUBCASE("Kruskal runs") {
        Graph kruskalTree = Algorithms::kruskal(g);
        CHECK(kruskalTree.getSize() == 5);
    }
}

/*
    Edge cases: invalid inputs and errors
*/
TEST_CASE("Edge cases and invalid inputs") {
    Graph g(3);

    SUBCASE("Out of range in getNeighbors") {
        CHECK_THROWS_AS(g.getNeighbors(-1), std::out_of_range);
        CHECK_THROWS_AS(g.getNeighbors(3), std::out_of_range);
    }

    SUBCASE("hasEdge with bad indices") {
        CHECK_THROWS_AS(g.hasEdge(0, 5), std::out_of_range);
        CHECK_THROWS_AS(g.hasEdge(-2, 1), std::out_of_range);
    }

    SUBCASE("Adding edge to self") {
        CHECK_THROWS_AS(g.addEdge(1, 1), std::invalid_argument);
    }

    SUBCASE("Adding edge with invalid indices") {
        CHECK_THROWS_AS(g.addEdge(-1, 2), std::out_of_range);
        CHECK_THROWS_AS(g.addEdge(1, 5), std::out_of_range);
    }

    SUBCASE("Removing non-existing edge") {
        CHECK_THROWS_AS(g.removeEdge(0, 1), std::invalid_argument);
    }

    SUBCASE("Removing edge with bad index") {
        CHECK_THROWS_AS(g.removeEdge(-1, 2), std::out_of_range);
    }
}
