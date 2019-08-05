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

void addLinkedList(NodeLinkedList* list, Node* node){
    NodeLinkedList* ptrTemp = list;
    while (ptrTemp->m_next != nullptr){
        ptrTemp = ptrTemp->m_next;
    }
    ptrTemp->m_next = new NodeLinkedList(node);
}

void createLinkedLists(std::vector<NodeLinkedList*> &linkedLists, Node* node, int level){
    
    if (node == nullptr) return; // base case
    
    NodeLinkedList* linkedList = nullptr;
    if (linkedLists.size() == level){
        linkedList = new NodeLinkedList(node);
        linkedLists.push_back(linkedList);
    }
    else{
        linkedList = linkedLists[level];
    }

    addLinkedList(linkedList, node);
    createLinkedLists(linkedLists, node->m_left, level+1);
    createLinkedLists(linkedLists, node->m_right, level+1);
}
std::vector<NodeLinkedList*> createLinkedLists(Node* root){
    std::vector<NodeLinkedList*> linkedLists;
    createLinkedLists(linkedLists, root, 0);
    return linkedLists;
}

void printLinkedList(NodeLinkedList* node){
    NodeLinkedList* ptrTemp = node;
    while (ptrTemp != nullptr){
        std::cout << ptrTemp->m_key->m_key << " ";
        ptrTemp = ptrTemp->m_next;
    }
}

void printLinkedLists(std::vector<NodeLinkedList*> list){
    int size = list.size();
    for (int i = 0; i < size; i++){
        std::cout << "List[" << i << "]: ";
        printLinkedList(list[i]);
        std::cout << std::endl;
    }
    
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
    linkedLists = createLinkedLists(root);
    printLinkedLists(linkedLists);
    return 0;
}