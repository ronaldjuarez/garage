#include <iostream>
#include <vector>

class Node{
    public:
        Node(const int value);
        int m_key;
        Node* m_left;
        Node* m_right;
};


Node::Node(const int value){
    m_key = value;
    m_left = nullptr;
    m_right = nullptr;
}

Node* insert(Node* node, int value){
    if (node == nullptr){
        return new Node(value);
    }
    if (node->m_key < value){
        node->m_right = insert(node->m_right, value);
    }
    else{
        node->m_left = insert(node->m_left, value);
    }
    return node;
}

class NodeLinkedList{
    public: 
        NodeLinkedList(Node* value);
        Node* m_key;
        NodeLinkedList* m_next;
};

NodeLinkedList::NodeLinkedList(Node* value){
    m_key = value;
    m_next = nullptr;
}
void createLinkedLists(std::vector<NodeLinkedList*> linkedLists, Node* root){
    int size = linkedLists.size();
    if (size == 
}
int main(){
    std::vector<NodeLinkedList*> linkedLists;
    Node* root = new Node(50);
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
    createLinkedLists(linkedLists, root);
    return 0;
}