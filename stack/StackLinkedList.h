#ifndef STACKLINKEDLIST_H_
#define STACKLINKEDLIST_H_

#include <iostream>
#include "StackADT.h"

template <class T>
struct StackNode {
    T data;
    StackNode<T>* next;

    StackNode(T& item, StackNode<T>* _next) {
        data = item;
        next = _next;
    }
};

template <class T>
class StackLinkedList : public StackADT<T> {
private:
    StackNode<T>* stackTop;
    int numNodes;

public:
    StackLinkedList();
    ~StackLinkedList();

    void initialize();
    bool isEmpty();
    bool isFull();
    void push(T&);
    void pop();
    T top();
    int size();

private:
    void makeEmpty();
};



template <class T>
StackLinkedList<T>::StackLinkedList() {
    stackTop = nullptr;
    numNodes = 0;
}

template <class T>
StackLinkedList<T>::~StackLinkedList() {
    initialize();
}

template <class T>
void StackLinkedList<T>::initialize() {
    while (!isEmpty()) {
        pop();
    }

    stackTop = nullptr;
    numNodes = 0;
}

template <class T>
bool StackLinkedList<T>::isEmpty() {
    return stackTop == nullptr;
}

template <class T>
bool StackLinkedList<T>::isFull() {
    return false;
}

template <class T>
void StackLinkedList<T>::push(T& item) {
    StackNode<T> *newNode = new StackNode<T>(item, stackTop);
    stackTop = newNode;
    numNodes++;
}

template <class T>
void StackLinkedList<T>::pop() {
    if (isEmpty()) {
        throw "Cannot pop from an empty linked list";
    }

    StackNode<T>* temp = stackTop;
    stackTop = stackTop->next;
    delete temp;
    numNodes--;
}

template <class T>
T StackLinkedList<T>::top() {
    return stackTop->data;
}

template <class T>
int StackLinkedList<T>::size() {
    return numNodes;
}


#endif // STACKLINKEDLIST_H_