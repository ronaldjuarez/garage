#include <vector>
#include <cmath>
#include <unordered_map>
#include <iostream>

struct TreeNode
{
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : key(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* leftNode, TreeNode* rightNode) : key(val), left(leftNode), right(rightNode) {}
};

void verticalOrderRecursive(
    TreeNode* root, 
    std::vector<std::vector<int>>& verticalOrderVector, 
    int pos,
    std::unordered_map<int, std::vector<int>>& verticalOrderMap)
{

    if (root == nullptr) return; 

    verticalOrderMap[pos].push_back(root->key);
    
    verticalOrderRecursive(root->left, verticalOrderVector, pos-1, verticalOrderMap);
    verticalOrderRecursive(root->right, verticalOrderVector, pos+1, verticalOrderMap);
}

std::vector<std::vector<int>> verticalOrder(TreeNode *root)
{
    int MAX_NODES = 100;
    std::vector<std::vector<int>> verticalOrderVector(static_cast<int>(ceil(log2(static_cast<double>(MAX_NODES)))) + 1);

    std::unordered_map<int, std::vector<int>> verticalOrderMap;
    verticalOrderRecursive(root, verticalOrderVector, 0, verticalOrderMap);

    for(auto it = verticalOrderMap.begin(); it != verticalOrderMap.end(); it++)
    {
        std::cout << it->first << ": ";

        for( int i = 0 ; i  < it->second.size() ; i++)
        {
            std::cout << it->second[i] << " ";
        }

        std::cout << std::endl;
    }
    return verticalOrderVector;
}

int main()
{
    TreeNode* leaf1 = new TreeNode(15);
    TreeNode* leaf2 = new TreeNode(7);
    TreeNode* leaf3 = new TreeNode(9);
    TreeNode* node1 = new TreeNode(20, leaf1, leaf2);
    TreeNode* root = new TreeNode(3,leaf3, node1);
    
    verticalOrder(root);
}