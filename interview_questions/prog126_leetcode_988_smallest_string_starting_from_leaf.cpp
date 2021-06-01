#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "helper.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void smallestFromLeafRec(
            TreeNode* node, 
            std::vector<std::string>& words, 
            std::string currWord)
{
    if (node == nullptr) 
    {
        return;
    }

    currWord = currWord + std::string(1,static_cast<char>('a' + node->val));

    if (node->left  == nullptr && 
        node->right == nullptr )
    {
        
        std::reverse(currWord.begin(), currWord.end());
        words.push_back(currWord);
        return;
    }

    if (node->left)
    {
        smallestFromLeafRec(node->left, words, currWord);
    }
    
    if (node->right)
    {
        smallestFromLeafRec(node->right, words, currWord);
    }

}

std::string smallestFromLeaf(TreeNode* root) 
{
    if (root == nullptr) return "";
    std::vector<std::string> words;

    smallestFromLeafRec(root, words, "");

    std::string minStr = words[0];

    for (size_t i = 1; i < words.size(); i++)
    {
        if (words[i] < minStr) minStr = words[i];
    }
    return minStr;
}

int main()
{
    TreeNode* child1 = new TreeNode(1, new TreeNode(3), new TreeNode(4));
    TreeNode* child2 = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    
    TreeNode* root = new TreeNode(0, child1, child2);
    
    std::cout << smallestFromLeaf(root) << std::endl;

    return 0;
}