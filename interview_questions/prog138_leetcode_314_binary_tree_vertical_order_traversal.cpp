#include <vector>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include "helper.h"
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* leftNode, TreeNode* rightNode) : val(val), left(leftNode), right(rightNode) {}
};

void verticalOrderRecursive(
    TreeNode* root,
    std::vector<std::vector<int>>& verticalOrderVector,
    int pos,
    std::unordered_map<int, std::vector<int>>& verticalOrderMap)
{
    if (root == nullptr) return; 
    
    verticalOrderMap[pos].push_back(root->val);
    verticalOrderRecursive(root->left, verticalOrderVector, pos-1, verticalOrderMap);
    verticalOrderRecursive(root->right, verticalOrderVector, pos+1, verticalOrderMap);
}

std::vector<std::vector<int>> verticalOrder(TreeNode* root)
{
    if (root == nullptr) return {};
    std::vector<std::vector<int>> verticalOrderVector;
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

std::vector<std::vector<int>> verticalOrder2(TreeNode* root)
{
    if (root == nullptr) return {};
    int minPos = INT_MAX, maxPos = INT_MIN;
    std::vector<std::vector<int>> verticalOrderVector;
    std::unordered_map<int, std::vector<int>> verticalOrderMap;
    std::queue<std::pair<int, TreeNode*>> q;
    
    q.push(std::pair<int, TreeNode*>(0, root));

    while (!q.empty())
    {
        std::pair<int, TreeNode*> currentPairNode = q.front(); q.pop();
        int currPos = currentPairNode.first;
        auto currNode = currentPairNode.second;


        verticalOrderMap[currPos].push_back(currNode->val);
        minPos = std::min(minPos, currPos);
        maxPos = std::max(maxPos, currPos);
        
        if (currNode->left != nullptr)
        {
            q.push(std::pair<int, TreeNode*>(currPos-1, currNode->left));
        }

        if (currNode->right != nullptr)
        {
            q.push(std::pair<int, TreeNode*>(currPos+1, currNode->right));
        }
    }

    for (int pos = minPos; pos <= maxPos; pos++)
    {
        if(!verticalOrderMap[pos].empty())
        {
            verticalOrderVector.push_back(verticalOrderMap[pos]);
        }
    }
   
    return verticalOrderVector;
}

int main()
{
    TreeNode* leaf2 = new TreeNode(2);
    TreeNode* leaf5 = new TreeNode(5);
    TreeNode* leaf4 = new TreeNode(4);
    TreeNode* leaf7 = new TreeNode(7);
    TreeNode* node0 = new TreeNode(0, nullptr, leaf2);
    TreeNode* node1 = new TreeNode(1, leaf5, nullptr);
    TreeNode* node9 = new TreeNode(9, leaf4, node0);
    TreeNode* node8 = new TreeNode(8, node1, leaf7);
    TreeNode* root = new TreeNode(3, node9, node8);

    auto result = verticalOrder2(root);
    
    Helper::print2D(result);
    TreeNode* leaf15 = new TreeNode(15);
    leaf7 = new TreeNode(7);
    TreeNode* leaf9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20, leaf15, leaf7);
    root = new TreeNode(3,leaf9, node20);
    std::cout << "test2" << std::endl;
    Helper::print2D(verticalOrder2(root));


    
    TreeNode* leaf10_1= new TreeNode(10);
    TreeNode* leaf11= new TreeNode(11);
    TreeNode* leaf10_2= new TreeNode(10);
    leaf9 = new TreeNode(9);
    leaf7 = new TreeNode(7);
    
    TreeNode* node7 = new TreeNode(7, nullptr, leaf10_1);
    node8 = new TreeNode(8, nullptr, leaf11);
    node9 = new TreeNode(9, leaf10_1, nullptr);

    TreeNode* node4 = new TreeNode(4, nullptr, node7);
    TreeNode* node5 = new TreeNode(5, node8, nullptr);
    TreeNode* node6 = new TreeNode(6, nullptr, node9);

    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3, node6, nullptr);

    root = new TreeNode(1, node2, node3);
    std::cout << "test3" << std::endl;
    Helper::print2D(verticalOrder2(root));
}