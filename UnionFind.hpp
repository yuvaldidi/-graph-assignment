// UnionFind.hpp
// yuvalgaddidi@gmail.com

#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

namespace graph {

// UnionFind class used for union-find algorithm (disjoint-set)
class UnionFind {
private:
    int* parent;
    int* rank;
    int size;

public:
    // Constructor: initializes the union-find structure
    UnionFind(int size);

    // Destructor: frees the memory used by the union-find structure
    ~UnionFind();

    // Finds the root of the set containing x
    int find(int x);

    // Unites the sets containing x and y
    void unite(int x, int y);
};

} // namespace graph

#endif
