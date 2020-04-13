#include <iostream>

using namespace std;

struct node {
    int value;
    node *next;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    void printList();

private:
    node *root;
    void add(node *root, int value);
    void destroyList(node *root);
    void printList(node *root);
};

LinkedList::LinkedList() {
    root = NULL;
}

LinkedList::~LinkedList() {
    destroyList(root);
}

void LinkedList::add(int value) {
    if(root == NULL) {
        root = new node;
        root->value = value;
        root->next = NULL;
    }else{
        add(root, value);
    }
}

void LinkedList::add(node *root, int value) {
    if(root->next == NULL) {
        root->next = new node;
        root->next->value = value;
        root->next->next = NULL;
    }else{
        add(root->next, value);
    }
}

void LinkedList::destroyList(node *root) {
    if(root != NULL) {
        destroyList(root->next);
        delete root;
    }
}

void LinkedList::printList() {
    printList(root);
}

void LinkedList::printList(node *root) {
    while(root != NULL) {
        cout << root->value << ',';
        root = root->next;
    }
}

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.add(9);
    list.add(10);

    list.printList();
}