#include <iostream>
#include <vector>
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
    return node->left  == nullptr &&
           node->right == nullptr;
}

void pathSumRec(
    TreeNode* node, 
    int targetSum,
    std::vector<std::vector<int>>& pathSums,
    std::vector<int> currentSumList, int currSum)
{
    if (node == nullptr)
    {
        return;
    }
    
    currentSumList.push_back(node->val);
    currSum += node->val;
    
    if (isLeaf(node))
    {
        if (targetSum == currSum)
        {
            pathSums.push_back(currentSumList);
        }
        return;
    }

    if (node->left)
    {
        pathSumRec(node->left, targetSum, pathSums, currentSumList, currSum);
    }
    if (node->right)
    {
        pathSumRec(node->right, targetSum, pathSums, currentSumList, currSum);
    }

}

std::vector<std::vector<int>> 
pathSum(TreeNode* root, int targetSum) {
    
    std::vector<std::vector<int>> pathSums;
    pathSumRec(root, targetSum, pathSums, {}, 0);
    return pathSums;
}

int main()
{
    TreeNode* grandchild1 = new TreeNode(11, new TreeNode(7), new TreeNode(2));
    TreeNode* grandchild2 = new TreeNode(4, new TreeNode(5), new TreeNode(1));

    TreeNode* child1 = new TreeNode(4, grandchild1, nullptr);
    TreeNode* child2 = new TreeNode(8, new TreeNode(13), grandchild2);
    TreeNode* root   = new TreeNode(5, child1, child2);

    Helper::print2D<int>(pathSum(root, 22));

    TreeNode* root2 = new TreeNode(-2, nullptr, new TreeNode(-3));
    Helper::print2D<int>(pathSum(root2, -5));

    return 0;
}