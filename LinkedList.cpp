// yuvaldaddidi@gmail.com

#include "LinkedList.hpp"

namespace graph {

// Create an empty list
LinkedList::LinkedList() : headNode(nullptr) {}

// Delete all nodes and free memory
LinkedList::~LinkedList() {
    while (headNode) {
        Node* temp = headNode;
        headNode = headNode->next;
        delete temp;
    }
}

// Add a neighbor at the beginning of the list
void LinkedList::insert(int vertex, int weight) {
    Node* newNode = new Node(vertex, weight);
    newNode->next = headNode;
    headNode = newNode;
}

// Remove a neighbor from the list
void LinkedList::remove(int vertex) {
    Node* current = headNode;
    Node* prev = nullptr;

    while (current) {
        if (current->vertex == vertex) {
            if (prev) prev->next = current->next;
            else headNode = current->next;

            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Check if a certain neighbor exists
bool LinkedList::contains(int vertex) const {
    Node* current = headNode;
    while (current) {
        if (current->vertex == vertex) return true;
        current = current->next;
    }
    return false;
}

// Print the whole list
void LinkedList::print() const {
    Node* current = headNode;
    while (current) {
        std::cout << "(" << current->vertex << ", " << current->weight << ") ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Count how many nodes are in the list
int LinkedList::size() const {
    int count = 0;
    Node* current = headNode;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Return the head of the list
Node* LinkedList::head() const {
    return headNode;
}

// Same as head(), used when comparing
Node* LinkedList::getHead() const {
    return headNode;
}

// Compare this list with another one
bool LinkedList::operator==(const LinkedList& other) const {
    Node* current1 = headNode;
    Node* current2 = other.headNode;

    while (current1 && current2) {
        if (current1->vertex != current2->vertex ||
            current1->weight != current2->weight)
            return false;

        current1 = current1->next;
        current2 = current2->next;
    }

    return current1 == nullptr && current2 == nullptr;
}

// Deep copy constructor
LinkedList::LinkedList(const LinkedList& other) : headNode(nullptr) {
    if (!other.headNode) return;

    headNode = new Node(other.headNode->vertex, other.headNode->weight);
    Node* currentSrc = other.headNode->next;
    Node* currentDest = headNode;

    while (currentSrc) {
        currentDest->next = new Node(currentSrc->vertex, currentSrc->weight);
        currentDest = currentDest->next;
        currentSrc = currentSrc->next;
    }
}

// Deep assignment
LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) return *this;

    // Delete current list
    while (headNode) {
        Node* temp = headNode;
        headNode = headNode->next;
        delete temp;
    }

    headNode = nullptr;
    if (!other.headNode) return *this;

    headNode = new Node(other.headNode->vertex, other.headNode->weight);
    Node* currentSrc = other.headNode->next;
    Node* currentDest = headNode;

    while (currentSrc) {
        currentDest->next = new Node(currentSrc->vertex, currentSrc->weight);
        currentDest = currentDest->next;
        currentSrc = currentSrc->next;
    }

    return *this;
}

} // namespace graph
