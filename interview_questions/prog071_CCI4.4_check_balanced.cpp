#include <iostream>

class Node{
    public:
        Node(int value);
        int m_key;
        Node* m_left;
        Node* m_right;
};

Node::Node(int value){
    m_key = value;
    m_left = nullptr;
    m_right = nullptr;
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
    private:
        bool hasChildren(Node*);
        Node* insertRecursive(Node* node, int value);
        void printRecursive(Node* node);
        int getHeightRecursive(Node* node);
        bool checkBalancedRecursive(Node* node);
        std::pair<bool,int> checkHeightRecursive(Node* node);
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

int Tree::getHeight(){
    return getHeightRecursive(root);
}

int Tree::getHeightRecursive(Node* node){
    if (node == nullptr) return -1;

    int max_left = getHeightRecursive(node->m_left);
    int max_right = getHeightRecursive(node->m_right);
    
    return 1 + std::max(max_left, max_right);
}

bool Tree::checkBalancedRecursive(Node* node){

    if (node == nullptr) return true;

    int height_left = getHeightRecursive(node->m_left);
    int height_right = getHeightRecursive(node->m_right);
    
    if (std::abs(height_left - height_right) > 1){
        return false;
    }
    else{
        return  checkBalancedRecursive(node->m_left) && checkBalancedRecursive(node->m_right);
    }
}

bool Tree::checkBalanced(){
    return checkBalancedRecursive(root);
}

int Tree::checkHeight(){
    std::pair<int,bool> result = checkHeightRecursive(root);
    return result.second;
}

bool Tree::hasChildren(Node* node){
    if (node == nullptr) return false;
    if (node->m_left != nullptr || node->m_right != nullptr) return true;
    return false;

}
std::pair<bool,int> Tree::checkHeightRecursive(Node* node){
    if (node == nullptr) return std::pair<bool,int>(false, -1);
    if (!hasChildren(node)) return std::pair<bool,int>(true, 0);
    
    std::pair<bool, int> balanced_left = checkHeightRecursive(node->m_left);
    if (balanced_left.first == false && balanced_left.second != -1)
        return std::pair<bool,int>(false, -2);
    std::pair<bool, int> balanced_right = checkHeightRecursive(node->m_right);
    if (balanced_right.first == false && balanced_right.second != -1)
        return std::pair<bool,int>(false, -2);

    int heightNode = 1 + std::max(balanced_left.second, balanced_right.second);

    if (abs(balanced_left.second - balanced_right.second) > 1) 
        return std::pair<bool,int>(false, heightNode);
    
    return std::pair<bool,int>(true, heightNode);
}

int main(){
    Tree tree(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.insert(75);
    tree.insert(45);
    tree.insert(47);
    //tree.insert(13);
    //tree.insert(35);
    tree.print();
    std::cout << std::endl;
    std::cout << tree.getHeight() << std::endl;
    std::cout << tree.checkBalanced() << std::endl;
    std::cout << tree.checkHeight() << std::endl;

    return 0;
}
