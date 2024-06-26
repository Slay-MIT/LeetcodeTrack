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

    TreeNode* BalancedBST(const vector<int>& inorder, int start, int end){

        if(start > end){
            return nullptr;
        }

        int mid  = start + (end-start)/2;
        TreeNode* leftTree = BalancedBST(inorder, start, mid-1);
        TreeNode* rightTree = BalancedBST(inorder, mid+1, end);
        
        // Create a new node with the middle element and attach the subtrees
        return new TreeNode(inorder[mid], leftTree, rightTree);
    }

    void TraverseNode(TreeNode* node, vector<int>& inorder){
        //traversing nodes to put them in an array in sorted order essentially
        
        if(!node){
            return;
        }
        TraverseNode(node->left, inorder);
        inorder.push_back(node->val);
        TraverseNode(node->right, inorder);
    
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;

        TraverseNode(root, inorder);
        int n = inorder.size();

        return BalancedBST(inorder, 0, n-1);
    }
};