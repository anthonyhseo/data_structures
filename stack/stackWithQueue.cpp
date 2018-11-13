#include <bits/stdc++.h>
using namespace std;

/*
* Implementing a stack with queues. We are using STL queues.
*
*/

class Stack {
    queue<int> q1, q2;
    int currentSize;

    public:
    Stack();
    void push(int x);
    void pop();
    int top();
    int size();
};

Stack::Stack() {
    currentSize = 0;
}

void Stack::push(int x) {
    currentSize++;
    q2.push(x);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

void Stack::pop() {
    if (q1.empty()) return;
    q1.pop();
    currentSize--;
}

int Stack::top() {
    if (q1.empty()) return -1;
    return q1.front();
}

int Stack::size() {
    return currentSize;
}


int main() {

    cout << "Hello World" << endl;

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.top() << " " << s.size() << endl;
    s.pop();
    cout << s.top() << " " << s.size() << endl;
    s.pop();
    s.pop();
    cout << s.top() << " " << s.size() << endl;
    


    return 0;
}