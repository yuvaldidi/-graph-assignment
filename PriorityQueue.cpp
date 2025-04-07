// yuvalgaddidi@gmail.com

#include "PriorityQueue.hpp"
#include <stdexcept>

// constructor
PriorityQueue::PriorityQueue() {
    capacity = 10;
    count = 0;
    data = new Item[capacity];
}

// destructor
PriorityQueue::~PriorityQueue() {
    delete[] data;
}

// doubles the array size
void PriorityQueue::resize() {
    capacity *= 2;
    Item* newData = new Item[capacity];
    for (int i = 0; i < count; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

// adds value and priority
void PriorityQueue::insert(int value, int priority) {
    if (count == capacity) {
        resize();
    }
    data[count++] = {value, priority};
}

// returns value with lowest priority
int PriorityQueue::extractMin() {
    if (count == 0) {
        throw std::runtime_error("priority queue is empty");
    }

    int minIndex = 0;
    for (int i = 1; i < count; ++i) {
        if (data[i].priority < data[minIndex].priority) {
            minIndex = i;
        }
    }

    int result = data[minIndex].value;
    data[minIndex] = data[--count];
    return result;
}

// true if empty
bool PriorityQueue::isEmpty() const {
    return count == 0;
}
