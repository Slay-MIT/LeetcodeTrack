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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        int postorderIndex = postorder.size() - 1;
        
        return buildTreeHelper(inorder, postorder, inorderMap, postorderIndex, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inorderMap, int& postorderIndex, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        
        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        int inorderIndex = inorderMap[rootVal];
        
        root->right = buildTreeHelper(inorder, postorder, inorderMap, postorderIndex, inorderIndex + 1, inorderEnd);
        root->left = buildTreeHelper(inorder, postorder, inorderMap, postorderIndex, inorderStart, inorderIndex - 1);
        
        return root;
    }
};