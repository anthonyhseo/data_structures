#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
using namespace std;

template <class T>
struct BinaryNode {
    T data;
    BinaryNode<T> *left;
    BinaryNode<T> *right;

    BinaryNode(const T& d, BinaryNode<T>* l, BinaryNode<T>* r)
        : data(d)
        , left(l)
        , right(r)
    {
    }
};

template <class T>
class BinarySearchTree {
private:
    BinaryNode<T>* root;
    
    void insert(BinaryNode<T>*&, const T&);
    void remove(BinaryNode<T>*&, const T&);
    // void removeMin(BinaryNode*&);
    BinaryNode<T>* findMin(BinaryNode<T>*);
    BinaryNode<T>* findMax(BinaryNode<T>*);
    void preorderPrint(BinaryNode<T>*);
    void inorderPrint(BinaryNode<T>*);
    void postorderPrint(BinaryNode<T>*);
    

public:
    BinarySearchTree();
    bool isEmpty();
    void insert(T&);
    T findMin();
    T findMax();
    void remove(const T&);
    
    void preorderPrint();
    void inorderPrint();
    void postorderPrint();
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template <class T>
void BinarySearchTree<T>::insert(T& item) {
    insert(root, item);
}

template <class T>
bool BinarySearchTree<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
void BinarySearchTree<T>::insert(BinaryNode<T>*& root, const T& item) {
    if (root == nullptr) {
        root = new BinaryNode<T>(item, nullptr, nullptr);
    } else if (item < root->data) {
        insert(root->left, item);
    } else if (item > root->data) {
        insert(root->right, item);
    } else {
        // duplicate data
        return;
    }
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findMin(BinaryNode<T>* t) {
    BinaryNode<T>* current = t;
    if (current == nullptr) {
        throw "Empty Binary Tree";
    }

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

template <class T>
T BinarySearchTree<T>::findMin() {
    return findMin(root)->data;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findMax(BinaryNode<T>* t) {
    BinaryNode<T>* current = t;
    if (current == nullptr) {
        throw "Empty Binary Tree";
    }

    while (current->right != nullptr) {
        current = current->right;
    }

    return current;
}

template <class T>
T BinarySearchTree<T>::findMax() {
    return findMax(root)->data;
}

template <class T>
void BinarySearchTree<T>::remove(BinaryNode<T>*& t, const T& x) {
    if (t == nullptr) {
        throw "Item not found";
    }

    if (x < t->data) {
        remove(t->left, x);
    } else if (x > t->data) {
        remove(t->right, x);
    } else if (t->left != nullptr && t->right != nullptr) {
        t->data = findMin(t->right)->data;
        remove(t->right, t->data);
    } else {
        BinaryNode<T>* oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

template <class T>
void BinarySearchTree<T>::remove(const T& x) {
    remove(root, x);
}

template <class T>
void BinarySearchTree<T>::inorderPrint() {
    inorderPrint(root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::inorderPrint(BinaryNode<T>* root) {
    if (root->left != nullptr) {
        inorderPrint(root->left);
    }
    cout << root->data << " ";
    if (root->right != nullptr) {
        inorderPrint(root->right);
    }
}

template <class T>
void BinarySearchTree<T>::preorderPrint() {
    preorderPrint(root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::preorderPrint(BinaryNode<T>* root) {
    if (root != nullptr) {
        cout << root->data << " ";
    }
    if (root->left != nullptr) {
        preorderPrint(root->left);
    }
    if (root->right != nullptr) {
        preorderPrint(root->right);
    }
}

template <class T>
void BinarySearchTree<T>::postorderPrint() {
    postorderPrint(root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::postorderPrint(BinaryNode<T>* root) {
    if (root == nullptr) return;
    if (root->left != nullptr) {
        postorderPrint(root->left);
    }
    if (root->right != nullptr) {
        postorderPrint(root->right);
    }
    cout << root->data << " ";
}


#endif