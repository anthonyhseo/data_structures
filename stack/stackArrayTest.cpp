#include <iostream>
#include "StackArray.h"

using namespace std;


int main() {
    
    StackArray<int> intStack(100);

    cout << "Testing empty stack. Expecting 1: " << intStack.isEmpty() << endl;
    cout << "Testing size. Expecting 0: " << intStack.size() << endl;

    for (int i = 0; i < 101; i++) {
        try {
            intStack.push(i);
        } catch (const char* e) {
            cout << e << endl;
        }
    }

    cout << "Testing size. Expecting 5: " << intStack.size() << endl;

    cout << "Popping everything off the stack: ";
    while (!intStack.isEmpty()) {
        cout << intStack.top() << " ";
        intStack.pop();
    }
    cout << '\n';

    cout << "Testing empty stack. Expecting 1: " << intStack.isEmpty() << endl;
    cout << "Testing size. Expecting 0: " << intStack.size() << endl;

    return 0;
}