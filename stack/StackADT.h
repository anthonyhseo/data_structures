#ifndef STACKADT_H_
#define STACKADT_H_

template <class T>
class StackADT {
public:
    virtual void initialize() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void push(T&) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual int size() = 0;
};

#endif // STACKADT_H_