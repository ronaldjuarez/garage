#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* next;
    Node* random;
};

Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->next = nullptr;
    node->random = nullptr;
}

Node* insert(Node* root, int key){
    if (root == nullptr){
        return newNode(key);
    }
    else{
        Node* pt = root;
        while (pt->next != nullptr){
            pt = pt->next;
        }
        Node* n = newNode(key);
        pt->next = n;
        
    }
}

void print(Node* root){
    Node* pt = root;
    while (pt != nullptr){
        cout << pt->key << " ";
        pt = pt->next;
    }
    cout << endl;
}

int main(){
    Node* root = newNode(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    root->random = root->next->next;
    root->next->random = root->next->next->next;
    root->next->next->random = root;
    root->next->next->next->random = root->next;
    print(root);
    cout << root->next->random->key<< endl;
    return 0;
}