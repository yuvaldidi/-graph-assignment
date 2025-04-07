// Algorithms.cpp
// yuvalgaddidi@gmail.com

#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"
#include "LinkedList.hpp"
#include "Graph.hpp"
#include <stdexcept>

namespace graph {

// helper function for dfs
void dfsVisit(const Graph& g, Graph& tree, bool* visited, int node) {
    visited[node] = true;
    const Node* neighbors = g.getNeighbors(node).head();
    while (neighbors) {
        int v = neighbors->vertex;
        if (!visited[v]) {
            tree.addEdge(node, v, neighbors->weight);
            dfsVisit(g, tree, visited, v);
        }
        neighbors = neighbors->next;
    }
}

// runs bfs and returns a bfs tree
Graph Algorithms::bfs(const Graph& g, int start) {
    int n = g.getSize();
    Graph tree(n);
    bool* visited = new bool[n]();
    Queue q;

    visited[start] = true;
    q.enqueue(start);

    while (!q.isEmpty()) {
        int curr = q.dequeue();
        const Node* neighbors = g.getNeighbors(curr).head();
        while (neighbors) {
            int v = neighbors->vertex;
            if (!visited[v]) {
                visited[v] = true;
                tree.addEdge(curr, v, neighbors->weight);
                q.enqueue(v);
            }
            neighbors = neighbors->next;
        }
    }

    delete[] visited;
    return tree;
}

// runs dfs and returns a dfs tree
Graph Algorithms::dfs(const Graph& g, int start) {
    int n = g.getSize();
    Graph tree(n);
    bool* visited = new bool[n]();
    dfsVisit(g, tree, visited, start);
    delete[] visited;
    return tree;
}

// returns shortest paths tree using dijkstra
Graph Algorithms::dijkstra(const Graph& g, int start) {
    int n = g.getSize();
    Graph tree(n);
    int* dist = new int[n];
    int* parent = new int[n];
    bool* visited = new bool[n]();

    for (int i = 0; i < n; ++i) {
        dist[i] = 999999;
        parent[i] = -1;
    }

    dist[start] = 0;
    PriorityQueue pq;
    pq.insert(start, 0);

    while (!pq.isEmpty()) {
        int u = pq.extractMin();
        if (visited[u]) continue;
        visited[u] = true;

        const Node* neighbors = g.getNeighbors(u).head();
        while (neighbors) {
            int v = neighbors->vertex;
            int w = neighbors->weight;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.insert(v, dist[v]);
            }
            neighbors = neighbors->next;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            tree.addEdge(i, parent[i]);
        }
    }

    delete[] dist;
    delete[] parent;
    delete[] visited;
    return tree;
}

// returns a minimum spanning tree using prim
Graph Algorithms::prim(const Graph& g) {
    int n = g.getSize();
    Graph tree(n);
    bool* inMST = new bool[n]();
    int* key = new int[n];
    int* parent = new int[n];

    for (int i = 0; i < n; ++i) {
        key[i] = 999999;
        parent[i] = -1;
    }

    key[0] = 0;
    PriorityQueue pq;
    pq.insert(0, 0);

    while (!pq.isEmpty()) {
        int u = pq.extractMin();
        inMST[u] = true;

        const Node* neighbors = g.getNeighbors(u).head();
        while (neighbors) {
            int v = neighbors->vertex;
            int w = neighbors->weight;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.insert(v, key[v]);
            }
            neighbors = neighbors->next;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            tree.addEdge(i, parent[i]);
        }
    }

    delete[] inMST;
    delete[] key;
    delete[] parent;
    return tree;
}

// returns a minimum spanning tree using kruskal
Graph Algorithms::kruskal(const Graph& g) {
    int n = g.getSize();
    Graph tree(n);
    UnionFind uf(n);

    // collect all edges
    struct Edge {
        int u, v, w;
    };

    Edge* edges = new Edge[n * n];
    int count = 0;

    for (int i = 0; i < n; ++i) {
        const Node* neighbors = g.getNeighbors(i).head();
        while (neighbors) {
            int j = neighbors->vertex;
            int w = neighbors->weight;
            if (i < j) {
                edges[count++] = {i, j, w};
            }
            neighbors = neighbors->next;
        }
    }

    // bubble sort by weight
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (edges[j].w > edges[j + 1].w) {
                Edge tmp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            tree.addEdge(u, v, edges[i].w);
        }
    }

    delete[] edges;
    return tree;
}

} // namespace graph
