// yuvalgaddidi@gmail.com

#include "Queue.hpp"
#include <stdexcept>

// constructor - starts with capacity 10
Queue::Queue() {
    capacity = 10;
    data = new int[capacity];
    frontIndex = 0;
    rearIndex = 0;
    count = 0;
}

// destructor - deletes array
Queue::~Queue() {
    delete[] data;
}

// doubles the array size
void Queue::resize() {
    int* newData = new int[capacity * 2];
    for (int i = 0; i < count; ++i) {
        newData[i] = data[(frontIndex + i) % capacity];
    }
    delete[] data;
    data = newData;
    frontIndex = 0;
    rearIndex = count;
    capacity *= 2;
}

// adds value to queue
void Queue::enqueue(int value) {
    if (count == capacity) {
        resize();
    }
    data[rearIndex] = value;
    rearIndex = (rearIndex + 1) % capacity;
    count++;
}

// removes value from queue
int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("queue is empty");
    }
    int result = data[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    count--;
    return result;
}

// true if empty
bool Queue::isEmpty() const {
    return count == 0;
}
