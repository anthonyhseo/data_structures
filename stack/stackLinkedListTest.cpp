#include <iostream>
#include "StackLinkedList.h"
using namespace std;

int main() {

    StackLinkedList<int> a;

    cout << "Testing size of Stack linked list. Expecting 0: " << a.size() << endl;

    for (int i = 0; i < 1000; i++) {
        a.push(i);
    }

    cout << a.size() << endl;

    while (!a.isEmpty()) {
        cout << a.top() << " ";
        a.pop();
    }

    cout << '\n';
    cout << "Testing if stack is empty. Expecting 1: " << a.isEmpty() << endl;
    cout << "Testing size of Stack linked list. Expecting 0: " << a.size() << endl;

    return 0;
}