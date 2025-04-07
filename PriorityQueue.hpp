// PriorityQueue.hpp
// yuvalgaddidi@gmail.com

#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

/*
A simple array-based priority queue.
Lowest priority value gets out first.
*/

class PriorityQueue {
private:
    struct Item {
        int value;
        int priority;
    };

    Item* data;
    int capacity;
    int count;

    // resizes the array when full
    void resize();

public:
    PriorityQueue();
    ~PriorityQueue();

    // adds item with priority
    void insert(int value, int priority);

    // removes and returns item with lowest priority
    int extractMin();

    // true if empty
    bool isEmpty() const;
};

#endif
