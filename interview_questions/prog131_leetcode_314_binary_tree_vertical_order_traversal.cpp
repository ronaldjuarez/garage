#include <vector>
#include <cmath>
#include <unordered_map>

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

}

std::vector<std::vector<int>> verticalOrder(TreeNode *root)
{
    int MAX_NODES = 100;
    std::vector<std::vector<int>> verticalOrderVector(static_cast<int>(ceil(log2(static_cast<double>(MAX_NODES)))) + 1);

    std::unordered_map<int, std::vector<int>> verticalOrderMap;
    verticalOrderRecursive(root, verticalOrderVector, 0, verticalOrderMap);
    return verticalOrderVector;
}

int main()
{

}