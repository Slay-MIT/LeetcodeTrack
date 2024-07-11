/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int TraverseSum(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }
        int curr = node->val;
        int left = max(0, TraverseSum(node->left, maxSum)); 
        int right = max(0, TraverseSum(node->right, maxSum));
        maxSum = max(maxSum, left + right + curr);
        return max(left, right) + curr;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = -1001;
        TraverseSum(root, maxSum);
        return maxSum;
    }
};