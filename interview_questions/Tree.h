#include <iostream>

class Node{
    public:
        Node(int value);
        bool isLeaf();
        int m_key;
        Node* m_left;
        Node* m_right;
        Node* parent;
};


Node::Node(int value){
    m_key = value;
    m_left = nullptr;
    m_right = nullptr;
}


bool Node::isLeaf(){
    if (this == nullptr) return false;
    if (m_left == nullptr || m_right == nullptr) return true;
    return false;
}

class Tree{
    public:
        Node* root;
        Tree();
        Tree(int value);
        void insert(int value);
        void print();
        bool checkBalanced();
        int getHeight();
        int checkHeight();
        bool isBST();
        Node* search(int key);
        Node* inOrderSuccessor(int value);
    private:
        bool hasChildren(Node*);
        Node* insertRecursive(Node* node, int value);
        void printRecursive(Node* node);
        int getHeightRecursive(Node* node);
        bool checkBalancedRecursive(Node* node);
        std::pair<bool,int> checkHeightRecursive(Node* node);
        bool isBSTRec(Node* node);
        Node* searchRec(Node* node, int value);
        Node* inOrderSuccessor(Node* node, int key);
};


Tree::Tree(){
    root = nullptr;
}
Tree::Tree(int value){
    root = new Node(value);
}

Node* Tree::insertRecursive(Node* node, int value){
    if (node == nullptr){
        node = new Node(value);
    }
    else{
        if (node->m_key <= value){
            node->m_right = insertRecursive(node->m_right, value);
        }
        else{
            node->m_left = insertRecursive(node->m_left, value);
        }
    }
    return node;
}

void Tree::insert(int value){
    root = insertRecursive(root, value);
}

void Tree::printRecursive(Node* node){
    if (node != nullptr){
        printRecursive(node->m_left);
        std::cout << node->m_key << " ";
        printRecursive(node->m_right);
    }
}

void Tree::print(){
    printRecursive(root);
}

Node* Tree::search(int value){
    return searchRec(root, value);
}

Node* Tree::searchRec(Node* node, int value){
    if (node == nullptr) return node;
    if (node->m_key == value ) return node;
    if (node->m_key >= value ) return searchRec(node->m_left, value);
    return searchRec(node->m_right, value);
}

