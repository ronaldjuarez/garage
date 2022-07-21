#include <vector>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include "helper.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* leftNode, TreeNode* rightNode) : key(val), left(leftNode), right(rightNode) {}
};

std::vector<std::vector<int>> verticalOrder2(TreeNode *root)
{
    int MAX_NODES = 100, minPos = INT_MAX, maxPos = INT_MIN;
    std::vector<std::vector<int>> verticalOrderVector;
    std::unordered_map<int, std::vector<int>> verticalOrderMap;
    std::queue<std::pair<int, TreeNode*>> q;
    std::set<int> visitedSet;
    
    q.push(std::pair<int, TreeNode*>(0, root));
    visitedSet.insert(root->val);

    while (!q.empty())
    {
        std::pair<int, TreeNode*> currentPairNode = q.front(); q.pop();
        int currPos = currentPairNode.first;
        auto currNode = currentPairNode.second;

        verticalOrderMap[currPos].push_back(currNode->val);

        minPos = std::min(minPos, currPos);
        maxPos = std::max(maxPos, currPos);
        
        if (currNode->left != nullptr && visitedSet.find(currNode->left->val) != visitedSet.end())
        {
            q.push(std::pair<int, TreeNode*>(currPos-1, currNode->left));
            visitedSet.insert(currNode->left->val);
        }

        if (currNode->right != nullptr && currNode->right->val)
        {
            q.push(std::pair<int, TreeNode*>(currPos+1, currNode->right));
            visitedSet.insert(currNode->right->val);
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
}