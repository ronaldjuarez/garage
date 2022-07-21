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
    int row,
    int col,
    std::unordered_map<int, std::vector<std::pair<int,int>>>& verticalOrderMap,
    int& min,
    int& max)
{

    if (root == nullptr) return; 

    verticalOrderMap[col].push_back(std::pair<int,int>(row, root->val));

    min = std::min(min, col);
    max = std::max(max, col);
    
    verticalOrderRecursive(root->left, verticalOrderVector, row+1, col-1, verticalOrderMap, min, max);
    verticalOrderRecursive(root->right, verticalOrderVector, row+1, col+1, verticalOrderMap, min, max);
}

bool compareOnlyFirst(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
{
    return p1.first < p2.first;
}

std::vector<std::vector<int>> verticalOrder_DFS(TreeNode *root)
{
    std::vector<std::vector<int>> verticalOrderVector;

    std::unordered_map<int, std::vector<std::pair<int,int>>> verticalOrderMap;
    int min = INT_MAX;
    int max = INT_MIN;
    verticalOrderRecursive(root, verticalOrderVector, 0, 0, verticalOrderMap, min, max);

    for (int key  = min ; key <= max ; key++)
    {
        std::cout << "Before sorting... (Current key: " << key << ")" << std::endl;
        for (int i = 0; i < verticalOrderMap[key].size() ; i++)
        {
            std::cout << "[" << verticalOrderMap[key][i].first << "," << verticalOrderMap[key][i].second << "]" << std::endl;
        }

        std::sort(verticalOrderMap[key].begin(), verticalOrderMap[key].end(), compareOnlyFirst);

        std::cout << "After sorting... (Current key: " << key << ")" << std::endl;
        for (int i = 0; i < verticalOrderMap[key].size() ; i++)
        {
            std::cout << "[" << verticalOrderMap[key][i].first << "," << verticalOrderMap[key][i].second << "]" << std::endl;
        }
        
        std::vector<int> currentColVector;
        std::for_each(verticalOrderMap[key].cbegin(), verticalOrderMap[key].cend(),
            [&](const std::pair<int,int>& elem){
                currentColVector.push_back(elem.second);
            });
        if (!verticalOrderMap[key].empty())
        {
            verticalOrderVector.push_back(currentColVector);
        }
    }

    return verticalOrderVector;
}

std::vector<std::vector<int>> verticalOrder(TreeNode* root)
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

    auto result = verticalOrder(root);
    
    Helper::print2D(result);
    TreeNode* leaf15 = new TreeNode(15);
    leaf7 = new TreeNode(7);
    TreeNode* leaf9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20, leaf15, leaf7);
    root = new TreeNode(3,leaf9, node20);
    std::cout << "test2" << std::endl;
    Helper::print2D(verticalOrder(root));

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
    Helper::print2D(verticalOrder(root));


    std::cout << "======= CASE 1 ======== " << std::endl;
    
    TreeNode* root2 = new TreeNode(3, new TreeNode(9, new TreeNode(4), new TreeNode(0)), new TreeNode(8, new TreeNode(1), new TreeNode(7)));
    auto result2 = verticalOrder(root2);
    Helper::print2D(result2);


    std::cout << "======= CASE 2 ======== " << std::endl;
    
    TreeNode* leaf2_4 = new TreeNode(4);
    TreeNode* leaf2_0 = new TreeNode(0);
    TreeNode* leaf2_1 = new TreeNode(1);
    TreeNode* leaf2_7 = new TreeNode(7);
    TreeNode* node2_9 = new TreeNode(9, leaf2_4, leaf2_0);
    TreeNode* node2_8 = new TreeNode(8, leaf2_1, leaf2_7);

    TreeNode* root3_3 = new TreeNode(3, node2_9, node2_8);
    Helper::print2D( verticalOrder(root3_3));

    std::cout << "======= CASE 3 ======== " << std::endl;

    TreeNode* leaf4_2 = new TreeNode(2);
    TreeNode* root4_1 = new TreeNode(1, leaf4_2, nullptr);
    Helper::print2D( verticalOrder(root4_1));

}