#include <iostream> 
class TreeNode{
    public:
        TreeNode(int value);
        int key;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
};

TreeNode::TreeNode(int value){
    key = value;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

class Tree{
    public:
        Tree():root(nullptr){};
        TreeNode* root;
        void insert(int value);
        void print();
        TreeNode* firstCommonAncestor(int value1, int value2);
        TreeNode* search(int value);
    private: 
        TreeNode* insertRec(TreeNode* &node, int value);
        void printRec(TreeNode* node);
        TreeNode* firstCommonAncestorRec(TreeNode* node1, TreeNode* node2);
        TreeNode* searchRec(TreeNode* node, int value);
        int depth(TreeNode* node);
        void goUpNode(TreeNode* &node, int value);
};

TreeNode*  Tree::insertRec(TreeNode* &node, int value){
    if (node == nullptr){
        node = new TreeNode(value);
        return node;
    }

    if (value <= node->key){
        node->left = insertRec(node->left, value);
        node->left->parent = node;
    }
    else if (value > node->key){
        node->right = insertRec(node->right, value);
        node->right->parent = node;
    }

    return node;
}
void Tree::insert(int value){
    insertRec(root, value);
}

void Tree::printRec(TreeNode* node){
    if (node != nullptr){
        printRec(node->left);
        std::cout << node->key << " ";
        printRec(node->right);
    }
}

void Tree::print(){
    printRec(root);
}

int Tree::depth(TreeNode* node){
    int count = 0;
    if (node == nullptr) return count;

    while (node != nullptr){
        count++;
        node = node->parent;
    }
    return count;
}

void Tree::goUpNode(TreeNode* &node, int value){
    while(value-- > 0 && node != nullptr){
        node = node->parent;
    }
}

TreeNode* Tree::firstCommonAncestorRec(TreeNode* node1, TreeNode* node2){
    int depthNode1 = depth(node1);
    int depthNode2 = depth(node2);
    int delta = depthNode1 - depthNode2;
    TreeNode* shallow = delta < 0? node1 : node2;
    TreeNode* deep = delta < 0? node2: node1;
    
    goUpNode(deep, abs(delta));

    while (shallow != deep && shallow != nullptr && deep != nullptr){
        shallow = shallow ->parent;
        deep = deep->parent;
    }

    return shallow == nullptr || deep == nullptr? nullptr:shallow;
}

TreeNode* Tree::firstCommonAncestor(int value1, int value2){
    TreeNode* node1 = search(value1);
    TreeNode* node2 = search(value2);
    return firstCommonAncestorRec(node1, node2);
}

TreeNode* Tree::searchRec(TreeNode* node, int value){
    if (node == nullptr) return nullptr;
    if (node->key == value) return node;

    if (value <= node->key){
        return searchRec(node->left, value);
    }
    return searchRec(node->right, value);
}

TreeNode* Tree::search(int value){
    return searchRec(root, value);
}

int main(){
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

    TreeNode* commonAncestor = tree.firstCommonAncestor(47,20);
	//TreeNode* node = tree.search(47);
	//node->m_key = 65;

	tree.print();
    std::cout << "\nCommon ancestor: " << commonAncestor->key << std::endl;

    return 0;
}