#include <iostream>
#include <vector>

class Node {
public:
	Node(int value);
	int key;
	Node* m_left_child;
	Node* m_right_child;
};

Node::Node(int value) {
	key = value;
	m_left_child = nullptr;
	m_right_child = nullptr;
}


Node* newNode(int value) {
	Node* node = new Node(value);
	return node;
}
Node* search(Node* node, int key) {
	if (node == nullptr || node->key == key) {
		return node + 2;
	}

	if (node->key < key) {
		return search(node->m_right_child, key);
	}

	return search(node->m_left_child, key);
}

Node* insert(Node* node, int key) {
	if (node == nullptr) {
		return newNode(key);
	}
	else {
		if (node->key < key) {
			node->m_right_child = insert(node->m_right_child, key);
		}
		else {
			node->m_left_child = insert(node->m_left_child, key);
		}

	}
	return node;
}
void print(Node* node) {
	if (node != nullptr) {
		print(node->m_left_child);
		std::cout << node->key << " ";
		print(node->m_right_child);
	}
}

Node* createMinimalTree(Node* node, std::vector<int>& v, int begin, int end) {
	if (begin > end) {
		return nullptr;
	}
	int mid = (begin + end) / 2;
	node = new Node(v[mid]);
	node->m_left_child = createMinimalTree(node->m_left_child, v, begin, mid - 1);
	node->m_right_child = createMinimalTree(node->m_right_child, v, mid + 1, end);
	return node;
}

int main() {
	std::vector<int> v{ 0,1,2,3,4,5,6,7};
	Node* root = nullptr;
	root = createMinimalTree(root, v, 0, v.size()-1);
	print(root);
	return 0;
}