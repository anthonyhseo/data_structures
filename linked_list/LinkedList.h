#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T> *next;
};

template <class T>
class LinkedList {
    private:
    Node<T> *head;
    Node<T> *last;
    int count;
    public:
    LinkedList();
    ~LinkedList();
    void insertFirst(T &a);
    void insertLast(T &a);
    void insert(int index, T &a);
    void deleteFirst();
    void deleteLast();
    T returnFirst();
    T returnLast();
    int size();

    int replace(T find, T with);

    void printLinkedList();
};

/*
* DESCRIPTION: Constructor for the LinkedList class. Creates an empty LinkedList
* head and last are null and count is set to 0.
*/
template <class T>
LinkedList<T>::LinkedList() {
    head = last = nullptr;
    count = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    // TODO: complete the destructor. delete all nodes to prevent memory leak.
    // cout << "DESTRUCTOR RUNNING\n";
    Node<T> *current = head;
    while (current != nullptr) {
        head = current;
        current = current->next;
        // cout << "Deleting: " << head->data << " " << &(*head) << endl;
        delete head;
        // cout << &head << ": " << head->data << endl;
    }
}

/*
* DESCRIPTION: Inserts element at the beginning of LinkedList.
*
*/
template <class T>
void LinkedList<T>::insertFirst(T &a) {
    Node<T> *newNode = new Node<T>;
    newNode->data = a;
    newNode->next = head;
    if (head == nullptr) {
        last = newNode;
    }
    head = newNode;
    count++;
}

template <class T>
void LinkedList<T>::insertLast(T &a) {
    Node<T> *newNode = new Node<T>;
    newNode->data = a;
    newNode->next = nullptr;

    // Inserting into empty LinkedList.
    if (head == nullptr) {
        head = last = newNode;
    // Inserting into non-empty LinkedList
    } else {
        last->next = newNode;
        last = newNode;
    }
    count++;
}

template <class T>
void LinkedList<T>::insert(int index, T &a) {
    if (index < 0 || index > count) {
        throw "Invalid index. Please enter a valid index.";
    }
    if (index == 0) {
        cout << "first\n";
        insertFirst(a);
    } else if (index == count) {
        cout << "last\n";
        insertLast(a);
    } else {
        Node<T> *previous, *current;
        Node<T> *newNode = new Node<T>;
        newNode->data = a;
        newNode->next = nullptr;
        current = head;
        while (index > 0) {
            previous = current;
            current = current->next;
            index--;
        }

        previous->next = newNode;
        newNode->next = current;
        count++;
    }
}

template <class T>
void LinkedList<T>::deleteFirst() {
    if (head == nullptr) {
        throw "Cannot delete first element of an empty LinkedList";
    }
    Node<T> *temp = head;
    head = head->next;
    count--;
    delete temp;
}

template <class T>
void LinkedList<T>::deleteLast() {
    if (head == nullptr) {
        throw "Cannot delete last element of an empty LinkedList";
    }
    Node<T> *current = head;
    while (current->next != last) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    last = current;
    count--;
}

template <class T>
T LinkedList<T>::returnFirst() {
    if (head == nullptr) {
        throw "Cannot return first element of an empty LinkedList";
    }
    return head->data;
}

template <class T>
T LinkedList<T>::returnLast() {
    if (last == nullptr) {
        throw "Cannot return last element of an empty LinkedList";
    }
    return last->data;
}


template <class T>
int LinkedList<T>::size() {
    return count;
}

template <class T>
int LinkedList<T>::replace(T find, T with) {
    Node<T> *current = head;
    int findCount = 0;
    while (current != nullptr) {
        if (current->data == find) {
            current->data = with;
            findCount++;
        }
        current = current->next;
    }

    return findCount;
}

template <class T>
void LinkedList<T>::printLinkedList() {
    Node<T> *current = head;
    if (current == nullptr) {
        cout << "Linked List is empty\n";
        return;
    }
    while (current->next != nullptr) {
        cout << current->data << "->";
        current = current->next;
    }
    
    cout << current->data << '\n';
}


#endif