#include <iostream>

class TreeNode {
public:
	TreeNode(int value);
	int m_key;
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode* m_parent;
};

TreeNode::TreeNode(int value) {
	m_key = value;
	m_left = nullptr;
	m_right = nullptr;
	m_parent = nullptr;
}

class Tree {
public:
	Tree();
	TreeNode* root;
	void insert(int value);
	void print();
	TreeNode* findInOrderSuccesor(int value);
    TreeNode* search(int value);
private:
	TreeNode* insertRec(TreeNode* &node, int value);
	void printRec(TreeNode* node);
	TreeNode* findInOrderSuccesorRec(TreeNode* node);
    TreeNode* searchRec(TreeNode* node, int value);
};

Tree::Tree() {
	root = nullptr;
}
void Tree::insert(int value) {
	insertRec(root, value);
}

TreeNode* Tree::insertRec(TreeNode* &node, int value) {

	if (node == nullptr) {
		node = new TreeNode(value);
		return node;
	}

	if (value <= node->m_key) {
		node->m_left = insertRec(node->m_left, value);
		node->m_left->m_parent = node;
	}
	else if (value > node->m_key) {
		node->m_right = insertRec(node->m_right, value);
		node->m_right->m_parent = node;
	}
	return node;
}

void Tree::print() {
	printRec(root);
}

void Tree::printRec(TreeNode* node) {
	if (node != nullptr) {
		printRec(node->m_left);
		std::cout << node->m_key << " ";
		printRec(node->m_right);
	}
}
TreeNode* Tree::findInOrderSuccesorRec(TreeNode* node) {
	if (node == nullptr) return nullptr;

	TreeNode* temp = node;

	if (temp->m_right != nullptr) {
		temp = temp->m_right;
		while (temp->m_left != nullptr)
			temp = temp->m_left;
	} 
	else {
		TreeNode* parent = temp->m_parent;
		while (parent != nullptr && parent->m_right == temp) {
			temp = parent;
			parent = parent->m_parent;
		}
		return parent;
	}
	return temp;
}

TreeNode* Tree::searchRec(TreeNode* node, int value){
    if (node == nullptr) return nullptr;
    if (node->m_key == value) return node;

    if (value <= node->m_key){
        return searchRec(node->m_left, value);
    }
    return searchRec(node->m_right, value);
}
TreeNode* Tree::search(int value){
    return searchRec(root, value);
}
TreeNode* Tree::findInOrderSuccesor(int value) {
    TreeNode* node = search(value);
	return findInOrderSuccesorRec(node);
}

int main() {
	Tree tree;
	tree.insert(50);
	tree.insert(30);
	tree.insert(20);
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	tree.insert(80);
	tree.insert(75);
	tree.insert(45);
	tree.insert(47);
	tree.insert(13);
	tree.insert(35);

	TreeNode* node = tree.search(47);
	node->m_key = 65;

	tree.print();
	std::cout << std::endl << tree.findInOrderSuccesor(30)->m_key << std::endl;
	return 0;
}
