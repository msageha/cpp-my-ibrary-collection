#include <iostream>

using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};

class BTree{
public:
    BTree();
    ~BTree();

    void insert(int key);
    node *search(int key);
    void destroy_tree();
    void inorder_print();
    void postoder_print();
    void preoder_print();

private:
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void inorder_print(node *leaf);
    void postoder_print(node *leaf);
    void preoder_print(node *leaf);

    node *root;
};

BTree::BTree(){ //コンストラクタ
    root = NULL;
}

BTree::~BTree(){ //デストラクタ
    destroy_tree();
}

void BTree::destroy_tree(node *leaf){
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BTree::destroy_tree(){
    destroy_tree(root);
}

void BTree::insert(int key, node *leaf) {
    if(key < leaf->value) {
        if(leaf->left != NULL) {
            insert(key, leaf->left);
        }else{
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else{
        if(leaf->right != NULL) {
            insert(key, leaf->right);
        }else{
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

void BTree::insert(int key){
    if(root != NULL) {
        insert(key, root);
    }else{
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *BTree::search(int key, node *leaf) {
    if(leaf != NULL) {
        if(key == leaf->value){
            return leaf;
        }else if(key < leaf->value){
            return search(key, leaf->left);
        }else{
            return search(key, leaf);
        }
    }else{
        return NULL;
    }
}

node *BTree::search(int key){
    return search(key, root);
}

void BTree::inorder_print(node *leaf) {
    if(leaf != NULL) {
        inorder_print(leaf->left);
        cout << leaf->value << ',';
        inorder_print(leaf->right);
    }
}

void BTree::inorder_print() {
    inorder_print(root);
    cout << endl;
}

void BTree::postoder_print(node *leaf) {
    if(leaf != NULL) {
        inorder_print(leaf->left);
        inorder_print(leaf->right);
        cout << leaf->value << ',';
    }
}

void BTree::postoder_print(){
    postoder_print(root);
    cout << '\n';
}

void BTree::preoder_print(node *leaf) {
    if (leaf != NULL) {
        cout << leaf->value << ',';
        inorder_print(leaf->left);
        inorder_print(leaf->right);
    }
}

void BTree::preoder_print() {
    preoder_print(root);
    cout << '\n';
}

int main() {
    //btree tree;
    BTree *tree = new BTree();
    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);

    tree->preoder_print();
    tree->inorder_print();
    tree->postoder_print();

    delete tree;
}