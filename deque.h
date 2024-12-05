#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>
#include <cstddef>

/**
 * @file Deque.h
 * @brief Declaration and implementation of the ADT Deque using a circular doubly linked chain.
 * 
 * This file provides the definition of the Deque class, a double-ended queue 
 * implemented using a circular doubly linked chain. The Deque supports adding 
 * and removing elements from both ends efficiently and retrieving the front 
 * and back elements.
 * 
 * @tparam T The type of elements stored in the Deque.
 */
template <typename T>
class Deque {
private:
    struct Node {
        T data;       ///< The data stored in the node.
        Node* next;   ///< Pointer to the next node.
        Node* prev;   ///< Pointer to the previous node.

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* front; ///< Pointer to the first node in the Deque.
    size_t size; ///< The number of elements in the Deque.

public:
    Deque() : front(nullptr), size(0) {}

    ~Deque() {
        while (!isEmpty()) {
            removeFront();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void addFront(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            front->next = front;
            front->prev = front;
        } else {
            Node* last = front->prev;
            newNode->next = front;
            newNode->prev = last;
            last->next = newNode;
            front->prev = newNode;
            front = newNode;
        }
        ++size;
    }

    void addBack(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            front->next = front;
            front->prev = front;
        } else {
            Node* last = front->prev;
            newNode->next = front;
            newNode->prev = last;
            last->next = newNode;
            front->prev = newNode;
        }
        ++size;
    }

    void removeFront() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty.");
        }
        Node* oldFront = front;
        if (size == 1) {
            front = nullptr;
        } else {
            Node* last = front->prev;
            front = front->next;
            last->next = front;
            front->prev = last;
        }
        delete oldFront;
        --size;
    }

    void removeBack() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty.");
        }
        Node* last = front->prev;
        if (size == 1) {
            front = nullptr;
        } else {
            Node* newLast = last->prev;
            newLast->next = front;
            front->prev = newLast;
        }
        delete last;
        --size;
    }

    T getFront() const {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty.");
        }
        return front->data;
    }

    T getBack() const {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty.");
        }
        return front->prev->data;
    }
};

#endif // DEQUE_H
