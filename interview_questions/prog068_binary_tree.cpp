#include <iostream>

class Node{
    public:
        Node(int value);
        int key;
        Node* m_left_child;
        Node* m_right_child;
};

Node::Node(int value){
    key = value;
    m_left_child = nullptr;
    m_right_child = nullptr;
}


Node* newNode(int value){
    Node* node = new Node(value);
    return node;
}
Node* search(Node* node, int key){
    if (node == nullptr || node->key == key){
        return node;
    }

    if (node->key < key){
        return search(node->m_right_child, key);
    }

    return search(node->m_left_child,key);
}

Node* insert(Node* node, int key){
    if (node == nullptr){
        return newNode(key);
    }
    else{
        if (node->key < key){
            node->m_right_child = insert(node->m_right_child, key);
        }
        else{
            node->m_left_child = insert(node->m_left_child,key);
        }

    }
    return node;
}
void print(Node* node){
    if (node != nullptr){
        print(node->m_left_child);
        std::cout << node->key << " ";
        print(node->m_right_child);
    }
}

int main(){
    Node* root = new Node(50);
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
    print(root);
    return 0;
}