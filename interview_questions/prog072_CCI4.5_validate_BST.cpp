#include <iostream>
#include "Tree.h"

bool Tree::isBST(){
    return isBSTRec(root);
}

bool Tree::isBSTRec(Node* node){
    if (node == nullptr) return true;
    if (node->isLeaf()) return true;
    if (node->m_key >= node->m_left->m_key &&
        node->m_key < node->m_right->m_key){
        bool leftResult = isBSTRec(node->m_left);
        bool rightResult = isBSTRec(node->m_right);
        return leftResult && rightResult;
    }
    return false;
}

void Tree::isBSTRec2(Node* node, std::vector<Node*> &nodes){
    
    if (node == nullptr) return;

    isBSTRec2(node->m_left, nodes);
    nodes.push_back(node);
    isBSTRec2(node->m_right, nodes);
}

bool Tree::isBST2(){
    std::vector<Node*> nodes;
    isBSTRec2(root, nodes);
    int size = nodes.size();
    for( int i = 1; i < size; i++){
        if (nodes[i]->m_key <= nodes[i-1]->m_key) return false;
    }

    return true;
}

bool Tree::isBSTRec3(Node* node, Node* &lastPrinted){
    if (node == nullptr) return true;

    if (!isBSTRec3(node->m_left, lastPrinted)) return false;
    
    if ( lastPrinted != nullptr && node->m_key < lastPrinted->m_key)
         return false;

    lastPrinted = node;

    if (!isBSTRec3(node->m_right, lastPrinted)) return false;

    return true;
}

bool Tree::isBST3(){
    Node* lastPrinted;
    return isBSTRec3(root, lastPrinted);
}

bool Tree::isBSTRec4(Node* node, Node* const &min, Node* const &max){
    if (node == nullptr) return true;

    if ((min != nullptr && node->m_key <= min->m_key) ||
        (max != nullptr && node->m_key > max->m_key) )
        return false;
    
    if( !isBSTRec4(node->m_left, min, node) || !isBSTRec4(node->m_right, node,max)){
        return false;
    }

    return true;
}

bool Tree::isBST4(){
    return isBSTRec4(root, nullptr, nullptr);
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

    Node* node = tree.search(47);
    node->m_key = 65;

    tree.print();

    std::cout << std::endl << tree.isBST4() << std::endl;

    return 0;
}
