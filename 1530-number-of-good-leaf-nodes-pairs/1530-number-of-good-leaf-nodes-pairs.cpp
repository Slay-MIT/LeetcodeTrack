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
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        helper(root, distance, count);
        return count;
    }

private:
    vector<int> helper(TreeNode* node, int distance, int& count) {
        if (node == nullptr) {
            return {};
        }

        // If it's a leaf node, return distance 1
        if (node->left == nullptr && node->right == nullptr) {
            return {1};
        }

        // Get distances of leaf nodes in left and right subtrees
        vector<int> leftDistances = helper(node->left, distance, count);
        vector<int> rightDistances = helper(node->right, distance, count);

        // Count pairs between left and right subtrees
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    count++;
                }
            }
        }

        // Collect current distances (incremented by 1) and return
        vector<int> currentDistances;
        for (int l : leftDistances) {
            if (l + 1 < distance) {
                currentDistances.push_back(l + 1);
            }
        }
        for (int r : rightDistances) {
            if (r + 1 < distance) {
                currentDistances.push_back(r + 1);
            }
        }

        return currentDistances;
    }
};
