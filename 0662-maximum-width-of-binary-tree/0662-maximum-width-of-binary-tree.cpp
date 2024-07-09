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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            maxWidth = max(maxWidth, int(right - left + 1));
            
            for (int i = 0; i < size; ++i) {
                auto [node, pos] = q.front();
                //Since the for loop is of the size of a level, it will keep popping till
                //all node of that level are gone
                q.pop();
                if (node->left) {
                    //2* because 1,2,4 and so on
                    q.push({node->left, 2 * pos + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * pos + 2});
                }
            }
        }
        
        return maxWidth;
    }
};