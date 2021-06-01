/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <string>
#include <iostream>
#include "helper.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode* node)
{
    return node->left == nullptr && node->right == nullptr;
}

void binaryTreePathsRec(TreeNode* node, std::vector<std::string>& paths, std::string currentPath)
{
    if (node == nullptr) return ;

    currentPath = currentPath + "->" + std::to_string(node->val);

    if (isLeaf(node)) 
    {
        paths.push_back(currentPath);
        return;
    }

    if (node->left != nullptr)
    {
        binaryTreePathsRec(node->left, paths, currentPath);
    }

    if (node->right != nullptr)
    {
        binaryTreePathsRec(node->right, paths, currentPath);
    }
}

std::vector<std::string> binaryTreePaths(TreeNode* root) 
{
    if (root == nullptr) return {};

    std::vector<std::string> paths;
    std::string currentPath = std::to_string(root->val);

    if (isLeaf(root)) 
    {
        paths.push_back(currentPath);
        return paths;
    }

    if (root->left != nullptr)
    {
        binaryTreePathsRec(root->left,paths,currentPath);
    }
    
    if (root->right != nullptr)
    {
        binaryTreePathsRec(root->right,paths,currentPath);
    }

    return paths;

}

int main()
{
    TreeNode* leaf = new TreeNode(5);
    TreeNode* child1 = new TreeNode(2, nullptr, leaf);
    TreeNode* child2 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, child1, child2);

    Helper::print1D(binaryTreePaths(root));
    Helper::print1D(binaryTreePaths(new TreeNode(1, nullptr, nullptr)));
    Helper::print1D(binaryTreePaths(new TreeNode(1, nullptr, child2)));

    return 0;
}