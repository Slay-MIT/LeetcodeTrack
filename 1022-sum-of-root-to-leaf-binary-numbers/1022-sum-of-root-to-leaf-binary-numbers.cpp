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
    int sumRootToLeaf(TreeNode* root) {
        return traverseTree(root, 0);
    }

    int traverseTree(TreeNode* node, int x){
        if(node == nullptr){
            return 0;
        }
        x = x*2 + node->val;
        if(node->left == node->right) return x;//that is it is null (reminder, we are working with pointers so node->left is a pointer not a value)
        return traverseTree(node->left, x) + traverseTree(node->right, x);
        
    }
};