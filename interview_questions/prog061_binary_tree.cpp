#include <iostream>
using namespace std;
struct node{
    int key;
    node *right;
    node *left;
    node *parent;
};

class BinaryTree{
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int key);
        void *search(int key);
        void destroy_tree();
        void print();
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        void print(node * leaf);
        node * search(int key, node *leaf);
        node * root;
};

// helper function
node * newNode(int key){
    node * n = new node; 
    n -> key = key;
    n -> left = nullptr;
    n -> right = nullptr;
    n -> parent = nullptr;
}
BinaryTree::BinaryTree(){
    root = nullptr;
}


BinaryTree::~BinaryTree(){
    destroy_tree();
}

void BinaryTree::destroy_tree(){
    destroy_tree(root);
}

void BinaryTree::destroy_tree(node *leaf){
    if (leaf != nullptr){
        destroy_tree(leaf -> left);
        destroy_tree(leaf -> right);
        delete leaf;
    }
}

void BinaryTree::insert(int key, node *leaf){

    if (key <= leaf->key){
        if (leaf->left != nullptr){
            insert(key, leaf->left);
        }
        else{
            node * n= newNode(key);
            leaf->left = n;
        }
    }
    else{
        if (leaf->right != nullptr){
            insert(key, leaf->right);
        }
        else{
            node * n = newNode(key);
            leaf->right = n;
        }
    }

}

node* BinaryTree::search(int key, node* leaf){

    if (key == leaf->key || leaf == nullptr){
        return leaf;
    }
    else{
        if (key <= leaf->key){
            search(key, leaf -> left);
        }
        else{
            search(key, leaf -> right);
        }
    }
    return nullptr;
}

void BinaryTree::insert(int key){
    if (root != nullptr){
        insert(key, root);
    }
    else{
        root = newNode(key);
    }

}

void BinaryTree::print(node *leaf){
    if (leaf != nullptr){
        print(leaf->left);
        cout << leaf -> key << " ";
        print(leaf->right);
    }
}

void BinaryTree::print(){
    print(root);
}
int main(){

    BinaryTree bt;
    bt.insert(20);
    bt.insert(9);
    bt.insert(25);
    bt.insert(5);
    bt.insert(12);
    bt.insert(11);
    bt.insert(14);


    bt.print();
    return 0;
}