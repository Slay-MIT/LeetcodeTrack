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
    
    int Traverse(TreeNode* node, int &maxDia){
        if(node==nullptr){
            return 0;
        }
        int lh = Traverse(node->left, maxDia);
        int rh = Traverse(node->right, maxDia);
        maxDia = max(maxDia, lh + rh);

        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        Traverse(root, maxDia);
        return maxDia;
    }
};