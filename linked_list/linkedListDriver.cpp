#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {

    /*
    LinkedList<int> list;

    list.printLinkedList();
    try {
        // list.deleteFirst();
        // list.deleteLast();
        // cout << list.returnFirst() << endl;
        int temp = 1234;
        list.insert(30, temp);
    } catch (const char *e) {
        cerr << "Something really bad happened: " << e << endl;
    }

    for (int i = 0; i < 10; i++) {
        list.insertFirst(i);
    }

    list.printLinkedList();
    cout << list.size() << " " << list.returnLast() << endl;
    list.deleteLast();
    list.deleteFirst();
    cout << list.size() << " " << list.returnLast() << endl;
    list.printLinkedList();
    */

    /*
    LinkedList<int> list;

    int item[] = {1, 9, 2, 9, 3, 9, 4, 9, 5};
    for(int i : item) {
        list.insertLast(i);
    }

    list.printLinkedList();

    cout << list.replace(9, 0) << endl;
    list.printLinkedList();
    */

    LinkedList<int> list;

    for (int i = 0; i < 10; i++) {
        list.insertLast(i);
    }

    list.printLinkedList();
    cout << list.size() << endl;

    try {
        int item = 123;
        list.insert(4, item);
    } catch (const char *e) {
        cerr << "Something went wrong: " << e << endl;
    }
    

    list.printLinkedList();
    cout << list.size() << endl;
    



    return 0;
}