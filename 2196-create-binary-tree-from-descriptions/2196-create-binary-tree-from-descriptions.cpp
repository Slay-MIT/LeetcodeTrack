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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> childSet;

        for(auto it: descriptions){
            int parentVal = it[0];
            int childVal = it[1];
            bool isLeft = it[2];

            //inserting parent value in map (by creating a node of same val at that index)
            if(nodes.find(parentVal) == nodes.end()){
                nodes[parentVal] = new TreeNode(parentVal);
            }

            //inserting child value in map " " " "" " " "
            if(nodes.find(childVal) == nodes.end()){
                nodes[childVal] = new TreeNode(childVal);
            }

            //if left, then connecting child value to parent value as left child
            if(isLeft){
                nodes[parentVal]->left = nodes[childVal];
            }
            // " " " " " " " " right child
            else{
                nodes[parentVal]->right = nodes[childVal];
            }

            //inserting all child nodes inside of a set so that we can find root easily later
            childSet.insert(childVal);
        }


        TreeNode* root = nullptr;
        //traversing the childSet to find a node that is NOT in it
        //the node that is not in this set is the root
        for(auto [val, node] : nodes){
            if(childSet.find(val) == childSet.end()){
                root = node;
                break;
            }
        }
        return root;
    }
};