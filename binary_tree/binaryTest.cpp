#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
    BinarySearchTree<int> a;
    
    cout << a.isEmpty() << endl;

    int z = 5;
    a.insert(z);
    z = 2;
    a.insert(z);
    z = 8;
    a.insert(z);
    z = 14;
    a.insert(z);
    z = 10;
    a.insert(z);
    z = 0;
    a.insert(z);
    z = 1;
    a.insert(z);
    z = -12;
    a.insert(z);

    a.inorderPrint();

    a.preorderPrint();

    a.postorderPrint();

    cout << a.isEmpty() << endl;
    cout << a.findMin() << endl;
    cout << a.findMax() << endl;

    try {
        z = -112;
        a.remove(z);
    } catch (const char* e) {
        cerr << e << endl;
    }

    a.inorderPrint();

    return 0;
}