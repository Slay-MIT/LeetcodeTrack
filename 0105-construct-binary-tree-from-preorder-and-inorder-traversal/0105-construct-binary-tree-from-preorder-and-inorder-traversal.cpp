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
    // Function to build the tree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in inorder traversal
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        // Variable to keep track of the current index in the preorder traversal
        int preorderIndex = 0;
        
        // Recursive function to build the tree
        return buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, 0, inorder.size() - 1);
    }
    
    // Helper function to build the tree recursively
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderMap, int& preorderIndex, int inorderStart, int inorderEnd) {
        // Base case: If there are no elements to construct the tree
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        
        // Get the root value from the current index of preorder traversal
        int rootVal = preorder[preorderIndex++];
        
        // Create the root node
        TreeNode* root = new TreeNode(rootVal);
        
        // Find the index of the root in inorder traversal
        int inorderIndex = inorderMap[rootVal];
        
        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, inorderStart, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, inorderIndex + 1, inorderEnd);
        
        return root;
    }
};