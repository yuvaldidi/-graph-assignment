// Queue.hpp
// yuvalgaddidi@gmail.com

#ifndef QUEUE_HPP
#define QUEUE_HPP

/*
A basic FIFO queue using a circular dynamic array
*/

class Queue {
private:
    int* data;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

    // resizes the array when it's full
    void resize();

public:
    Queue();
    ~Queue();

    // adds value to the end
    void enqueue(int value);

    // removes and returns value from front
    int dequeue();

    // true if queue is empty
    bool isEmpty() const;
};

#endif
