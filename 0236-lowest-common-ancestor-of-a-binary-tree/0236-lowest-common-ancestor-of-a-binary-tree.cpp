/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == q || root == p){
            //NOTE: returning root if it is NULL as well
            //the root can hence hold the NULL value here (usually we did return; )
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr){
            //it not in left subtree
            return right;
        }
        else if(right == nullptr){
            //if not in right subtree
            return left;
        }
        else{
            //if both found in the same subtree
            return root;
        }
    }
};