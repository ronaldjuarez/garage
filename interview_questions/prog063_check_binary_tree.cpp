#include <iostream>
#include <climits>

using namespace std;
struct Node {
	int key;
	Node* left;
	Node* right;
	Node* parent;
};

Node* newNode(int key) {
	Node* node = new Node();
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;
	node->parent = nullptr;
	return node;
}

Node *insert(Node* &node, int key) {
	if (node == nullptr) {
		node = newNode(key);
	}
	else {
		if (key <= node->key) {
			Node* temp = insert(node->left, key);
			node->left = temp;
			temp->parent = node;
		}
		else {
			Node* temp = insert(node->right, key);
			node->right = temp;
			temp->parent = node;
		}
	}
	return node;
}

Node* search(Node* node, int key) {
	Node * n = new Node();
	if (node == nullptr || node->key == key) {
		n = node;
	}
	else {
		if (key < node->key) {
			n = search(node->left, key);
		}
		else {
			n = search(node->right, key);
		}
	}
	return n;
}

void print(Node* node) {
	if (node != nullptr) {
		print(node->left);
		cout << node->key << " ";
		print(node->right);
	}
}

Node* findInOrderSuccessor(Node* inputNode){
    Node* n;    
    if (inputNode->right != nullptr){
        Node* pt = inputNode->right;
        while (pt->left != nullptr){
            pt = pt->left;
        }
        n = pt;
    }
    else{
        Node* parent = inputNode->parent;   
        Node* pt = inputNode;

        while (parent != nullptr && parent->right == pt){
            pt = parent;
            parent = parent->parent;
        }
        n = parent;
    }

    return n;
}

bool isBST_rec(Node *root,int liminf,int limsup){
    
    if (root == nullptr){
        return true;
    }
    else if (liminf < root->key &&  root->key <= limsup){
        return isBST_rec(root->left, liminf, root->key) && isBST_rec(root->right, root->key, limsup);
    }
    else{
        return false;
    }
}

bool isBST(Node* root){
    int liminf = INT_MIN, limsup = INT_MAX;
    return isBST_rec(root, liminf, limsup);
}

int main() {

    Node* root = newNode(10);
    insert(root, 7);
    insert(root, 15);
    insert(root, 3);
    insert(root, 8);
    insert(root, 12);
    insert(root, 17);
    //Node* n = search(root, 12);
    //n->key = 9;
    print(root);
    cout<< endl;
    
    cout << isBST(root) << endl;
    cout << INT_MAX << INT_MIN << endl;

    /*
	Node* root = newNode(20);
	insert(root, 9);
	insert(root, 25);
	insert(root, 5);
	insert(root, 12);
	insert(root, 11);
	insert(root, 14);
	print(root);
    cout << endl;
    Node* n = search(root, 9);
    Node* successor = findInOrderSuccessor(n);
    cout << successor->key << endl;
    */
	return 0;
}

