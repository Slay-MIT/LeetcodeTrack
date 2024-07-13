/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // Start with the leftmost node of the tree (which is root initially)
        Node* leftmost = root;

        while (leftmost->left != nullptr) {
            // Traverse the current level and setup pointers for the next level
            Node* head = leftmost;
            
            while (head != nullptr) {
                // Connect the left child to the right child of the same parent
                head->left->next = head->right;
                
                // Connect the right child to the left child of the next parent
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }
                
                // Move to the next node in the current level
                head = head->next;
            }
            
            // Move to the next level
            leftmost = leftmost->left;
        }
        
        return root;
    }
};