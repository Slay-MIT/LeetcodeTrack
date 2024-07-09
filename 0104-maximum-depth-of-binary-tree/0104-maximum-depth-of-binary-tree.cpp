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
class Solution {
public:
    
    void Traverse(TreeNode* node, int &maxLevel, int level){
        if(node == nullptr){
            return;
        }
        maxLevel = max(maxLevel, level);
        if(node->left)Traverse(node->left, maxLevel, level+1);
        if(node->right)Traverse(node->right, maxLevel, level+1);
    }

    int maxDepth(TreeNode* root) {
        int maxLevel = 1;
        Traverse(root, maxLevel, 1);
        return maxLevel;
    }
};