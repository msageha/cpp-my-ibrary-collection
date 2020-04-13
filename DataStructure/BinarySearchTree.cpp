#include <iostream>

using namespace std;

template <class T>
struct node{
    T value;
    node *right;
    node *left;
};

template <class T>
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void add(T value);
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    int size();
    bool lookup(T value);

private:
    node<T> *root;
    int treeSize;
    void add(node<T> *node, T value);
    bool lookup(node<T> *node, T value);
    void printPreOrder(node<T> *node);
    void printInOrder(node<T> *node);
    void printPostOrder(node<T> *node);
    void deleteTree(node<T> *node);
};

template <class T>
BinaryTree<T>::BinaryTree() {
    this->root = NULL;
    this->treeSize = 0;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    deleteTree(this->root);
}

template <class T>
int BinaryTree<T>::size() {
    return this->treeSize;
}

template <class T>
void BinaryTree<T>::add(T value) {
    add(this->root, value);
}

template <class T>
void BinaryTree<T>::add(node<T> *node, T value) {
    if(node == NULL) {
        node<T> temp = new node;
        temp->value = value;
        temp->left = NULL;
        temp->right = NULL;
        node = temp;
        this->treeSize++;
    }else{
        if(value > node->value) {
            add(node->right, value);
        }else {
            add(node->left, value);
        }
    }
}

template <class T>
void BinaryTree<T>::printInOrder() {
    printInOrder(this->root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printInOrder(node<T> *node) {
    if(node != NULL) {
        printInOrder(node->left);
        cout << node->value << ',';
        printInOrder(node->right);
    }
}

template <class T>
void BinaryTree<T>::printPreOrder() {
    printPreOrder(this->root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printPreOrder(node<T> *node) {
    if (node != NULL) {
        cout << node->value << ',';
        printInOrder(node->left);
        printInOrder(node->right);
    }
}

template <class T>
void BinaryTree<T>::printPostOrder() {
    printPostOrder(this->root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printPostOrder(node<T> *node) {
    if (node != NULL) {
        printInOrder(node->left);
        printInOrder(node->right);
        cout << node->value << ',';
    }
}
template <class T>
void BinaryTree<T>::deleteTree(node<T> *node) {
    if(node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template <class T>
bool BinaryTree<T>::lookup(T value) {
    return lookup(this->root, value);
}

template <class T>
bool BinaryTree<T>::lookup(node<T> *node, T value) {
    if (node == NULL) {
        return false;
    }else{
        if(value == node->value) {
            return true;
        }

        if(value > node->value) {
            return lookup(node->right, value);
        }else {
            return lookup(node->left, value);
        }
    }
}

int main() {
    BinaryTree<int> tree;

    tree.add(5);
    tree.add(4);
    tree.add(7);
    tree.add(10);
    tree.add(1);
    tree.add(2);

    tree.printPostOrder();
    tree.printInOrder();
    tree.printPreOrder();

    cout << "Tree size:" << tree.size() << endl;

    BinaryTree<char> tee;

    tee.add('z');
    tee.add('0');
    tee.add('9');
    tee.add('a');
    tee.add('A');
    tee.add('Z');

    std::cout << "Contains 9? : "<< ((tee.lookup('9'))? "true" : "false" ) << std::endl;

    tee.printPostOrder();
    tee.printInOrder();
    tee.printPreOrder();

    std::cout << "Tree size: " << tee.size() << std::endl;
}