#include <iostream>
#include "Tree.h"


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
    Node* node = tree.search(47);
    node->m_key = 65;
    //tree.insert(13);
    //tree.insert(35);
    tree.print();
    std::cout << std::endl << tree.isBST() << std::endl;

    return 0;
}
