#pragma once

#include <type_traits>
#include <iterator>
#include <stdexcept>

template<typename T>
class LinkedList {
    struct Node {
        explicit Node(T aElement) : element(aElement) {};
        T element;
        Node *nextNode = nullptr;
        Node *prevNode = nullptr;
    };

    Node *front = nullptr;
    Node *back = nullptr;
public:
    LinkedList() = default;

    LinkedList(const LinkedList &obj) {
        if (obj.front == nullptr) return;

        Node *node = obj.front;
        push_back(node->element);

        while (node->nextNode != nullptr) {
            node = node->nextNode;
            push_back(node->element);
        }
    };

    void push_back(T element) {
        Node *newNode = new Node(element);

        if (front == nullptr) {
            front = newNode;
            back = newNode;
            return;
        }

        Node *oldBack = back;
        back->nextNode = newNode;
        newNode->prevNode = oldBack;
        back = newNode;
    };

    T pop_back() {
        if (back == nullptr) {
            throw std::out_of_range("There are no elements in the list");
        }

        if (size() == 1) {
            front = nullptr;
        }

        T value = back->element;
        Node *newBack = back->prevNode;
        if (newBack != nullptr) newBack->nextNode = nullptr;
        delete back;
        back = newBack;
        return value;
    };

    [[nodiscard]] const T& peek_back() const {
        if (back == nullptr) {
            throw std::out_of_range("There are no elements in the list");
        }

        return back->element;
    };

    [[nodiscard]] int size() const {
        int counter = 0;
        Node *lastNode = front;
        while (lastNode != nullptr) {
            lastNode = lastNode->nextNode;
            counter++;
        }
        return counter;
    };

    ~LinkedList() {
        if (front == nullptr) return;
        Node *node = front;
        Node *next;
        while (node != nullptr) {
            next = node->nextNode;
            delete node;
            node = next;
        }
    }

};

template <typename T>
class Stack : private LinkedList<T> {
public:
    void push(T element) {
        push_back(element);
    };

    T pop() {
        return pop_back();
    };

    T peek() {
        return peek_back();
    };

    int size() {
        return LinkedList::size();
    };
};