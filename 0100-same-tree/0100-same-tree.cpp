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
    void Traverse(TreeNode* p, TreeNode* q, bool& flag) {
        if (!flag)
            return; // early exit condition
        if (p == nullptr && q == nullptr) {
            // both nodes are null
            return;
        }
        if (p == nullptr || q == nullptr) {
            // one of the two is null which means trees are unequal
            flag = false;
            return;
        }
        if (p->val != q->val) {
            flag = false;
        }
        Traverse(p->left, q->left, flag);
        Traverse(p->right, q->right, flag);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        Traverse(p, q, flag);
        return flag;
    }
};