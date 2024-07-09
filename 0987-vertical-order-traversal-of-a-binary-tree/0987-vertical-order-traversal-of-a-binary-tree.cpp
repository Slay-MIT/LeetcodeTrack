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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Base case
        if (!root) return {};

        // Map to hold vertical order traversal
        // map[column, map[row, vector of node values]]
        map<int, map<int, vector<int>>> nodes;
        // Queue for BFS traversal, holds node and its column and row
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            nodes[col][row].push_back(node->val);
            
            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> result;
        
        for (auto& colPair : nodes) {
            vector<int> colVals;
            for (auto& rowPair : colPair.second) {
                vector<int>& vals = rowPair.second;
                sort(vals.begin(), vals.end());
                colVals.insert(colVals.end(), vals.begin(), vals.end());
            }
            result.push_back(colVals);
        }
        
        return result;
    }
};