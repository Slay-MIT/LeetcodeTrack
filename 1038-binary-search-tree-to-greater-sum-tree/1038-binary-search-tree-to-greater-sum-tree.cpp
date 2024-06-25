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

    //Notice how I used &NodeSum instead of just NodeSum; avoid using global variables
    //Instead just point to the variable you've declared before
    void traverseTree(TreeNode* node, int &NodeSum){

        //The moment you finish traversing the subtrees, you will reach the NULL node
        //recursively go back now
        if(node == NULL){
            return;
        }


        //Traverse the right subtree tree
        traverseTree(node->right, NodeSum);
        
        //Add current node val to the NodeSum
        NodeSum += node->val;

        //Update current node val to NodeSum 
        node->val = NodeSum;
        
        //Traverse the left subtree tree
        traverseTree(node->left, NodeSum);
    }

    TreeNode* bstToGst(TreeNode* root) {

        int NodeSum = 0;
        traverseTree(root, NodeSum);
        return root;
    }
};