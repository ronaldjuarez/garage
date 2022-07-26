#include <iostream>

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val) : val (val), left (nullptr), right(nullptr), parent(nullptr) {}
    Node(int val, Node* left, Node* right): val (val), left (left), right(right), parent(nullptr) {}
};

class Solution
{
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p;
        Node* b = q;

        while ( a != b )
        {
            a = a == nullptr? q : a->parent;
            b = b == nullptr? p : b->parent;
        }
        return a;
    }
};

int main()
{
    Solution sol;


    Node* leaf1_7 = new Node(7);
    Node* leaf1_4 = new Node(4);
    Node* leaf1_6 = new Node(6);
    Node* leaf1_0 = new Node(0);
    Node* leaf1_8 = new Node(8);

    Node* node1_2 = new Node(2, leaf1_7, leaf1_4);
    leaf1_7->parent = node1_2;
    leaf1_4->parent = node1_2;

    Node* node1_5 = new Node(5, leaf1_6, node1_2);
    leaf1_6->parent = node1_5;
    node1_2->parent = node1_5;

    Node* node1_1 = new Node(1,leaf1_0, leaf1_8);
    leaf1_0->parent = node1_1;
    leaf1_8->parent = node1_1;

    Node* root1_3 = new Node(3, node1_5, node1_1);
    node1_5->parent = root1_3;
    node1_1->parent = root1_3;

    Node* lca = sol.lowestCommonAncestor(node1_5, node1_1);
    std::cout << "lca: " << lca->val << std::endl;

    lca = sol.lowestCommonAncestor(leaf1_6, leaf1_4);
    std::cout << "lca: " << lca->val << std::endl;

    return 0;   
}