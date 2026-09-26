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
    bool isBalanced(TreeNode* root) {
        if (!root) { return true; }
        if (abs(heightOfTree(root->left) - heightOfTree(root->right)) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int heightOfTree(TreeNode* node) {
        if (!node) { return 0; }
        return 1 + max(heightOfTree(node->left), heightOfTree(node->right));
    };
};
