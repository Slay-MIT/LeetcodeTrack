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
            return root;
        }
        //Note: we didn't do the left and right thing here as that would require us to put
        //the left and right inside of conditional statements which will cause them to be not
        //usable outside of those statements
        //returning the function itself is the easiest way to do this
       
       if(p->val < root->val && q->val < root->val){
        //if both exist in the left subtree
            return lowestCommonAncestor(root->left, p, q);
       }

       if(p->val > root->val && q->val > root->val){
        //if both exist in the right subtree
            return lowestCommonAncestor(root->right, p, q);
       }

        //if they exist in separate subtrees (one in left one in right)
       return root;
    }
};