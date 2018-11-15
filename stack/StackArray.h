#ifndef STACKARRAY_H_
#define STACKARRAY_H_

#include "StackADT.h"

template <class T>
class StackArray : public StackADT<T> {
    private:
    T *array;
    int stackTop;
    int capacity;

    public:
    StackArray(int);
    ~StackArray();

    void initialize();
    bool isEmpty();
    bool isFull();
    void push(T&);
    void pop();
    T top();
    int size();
};

template <class T>
StackArray<T>::StackArray(int _stackTop) {
    array = new T[_stackTop];
    capacity = _stackTop;
    stackTop = 0;
}

template <class T>
StackArray<T>::~StackArray() {
    delete [] array;
}

template <class T>
void StackArray<T>::initialize() {
    stackTop = 0;
}

template <class T>
bool StackArray<T>::isEmpty() {
    return stackTop == 0;
}

template <class T>
bool StackArray<T>::isFull() {
    return stackTop == capacity;
}

template <class T>
void StackArray<T>::push(T& item) {
    if (isFull()) {
        throw "cannot insert, Stack is full";
    }

    array[stackTop++] = item;
}

template <class T>
void StackArray<T>::pop() {
    stackTop--;
}

template <class T>
T StackArray<T>::top() {
    if (isEmpty()) {
        throw "Cannot return object from an empty stack";
    }
    return array[stackTop - 1];
}

template <class T>
int StackArray<T>::size() {
    return stackTop;
}


#endif // STACKARRAY_H_