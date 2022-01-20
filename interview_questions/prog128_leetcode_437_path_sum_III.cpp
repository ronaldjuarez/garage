#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
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

void pathRec
(
    TreeNode* node, 
    std::vector<std::vector<int>>& allPaths,
    std::vector<int> currPath
)
{
    if (node == nullptr)
    {
        return;
    }

    currPath.push_back(node->val);

    if (isLeaf(node))
    {
        allPaths.push_back(currPath);
        return;
    }

    if (node->left)
    {
        pathRec(node->left, allPaths, currPath);
    }

    if (node->right)
    {   
        pathRec(node->right, allPaths, currPath);
    }

}

bool isIn(
    std::vector<std::vector<int>>& targetPathsSum,
    std::vector<int>& currPath)
{
    for (const auto& path : targetPathsSum)
    {
        if (path == currPath) return true;
    }
    return false;
}

void addToTargetPathsUnique(
    std::vector<std::vector<int>>& targetPathsSum,
    std::vector<int> currPath
)
{
    if (!isIn(targetPathsSum,currPath))
    {
        targetPathsSum.push_back(currPath);
    }
}

bool exist(const std::unordered_map<int,int>& map, int key)
{
    return map.find(key) != map.end();
}

int findPathsforTargetSum(
     std::vector<std::vector<int>> allPaths, 
     int targetSum)
 {
     
    int count = 0;
    for(auto& currPath : allPaths)
    {
        if (currPath.size() == 0) continue;
        size_t i = 0, j = 1;
        size_t n = currPath.size();
        
        std::unordered_map<int,int> map;
    
        int cumSum = 0;
        for (size_t i = 0; i < currPath.size(); i++)
        {
            cumSum += currPath[i];
            
            if (cumSum == targetSum)
            {
                count++;
            }

            if (exist(map, cumSum-targetSum))
            {
                count += map[cumSum-targetSum];
            }
            map[cumSum]++;
        }
    }
    return count;
 }

int pathSum(TreeNode* root, int targetSum) 
{
    std::vector<std::vector<int>> allPaths;
    pathRec(root, allPaths, {});
    Helper::print2D<int>(allPaths);
    int count = findPathsforTargetSum(allPaths, targetSum);
    return count;
}

int pathSum2(TreeNode* root, int targetSum) 
{
    std::vector<std::vector<int>> allPaths;
    pathRec(root, allPaths, {});
    Helper::print2D<int>(allPaths);
    int count = findPathsforTargetSum(allPaths, targetSum);
    return count;
}


int main()
{
    TreeNode* grandchild1 = new TreeNode(3, new TreeNode(3), new TreeNode(-2));
    TreeNode* grandchild2 = new TreeNode(2, nullptr, new TreeNode(1));

    TreeNode* child1 = new TreeNode(5, grandchild1, grandchild2);
    TreeNode* child2 = new TreeNode(-3, nullptr, new TreeNode(11));
    TreeNode* root   = new TreeNode(10, child1, child2);
    std::cout << pathSum(root, 8) << std::endl;
    // Helper::print2D<int>(pathSum(root, 22));

    // TreeNode* root2 = new TreeNode(-2, nullptr, new TreeNode(-3));
    // Helper::print2D<int>(pathSum(root2, -5));


    TreeNode* root2 = new TreeNode(1);

    std::cout << pathSum(root2, 0) << std::endl;

    TreeNode* root3 = new TreeNode(1, new TreeNode(2), nullptr);

    std::cout << pathSum(root3, 0) << std::endl;

    return 0;
}