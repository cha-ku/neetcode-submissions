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
        int l = heightOf(root->left);
        int r = heightOf(root->right);
        if (abs(l - r) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int heightOf(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int l = 1 + heightOf(node->left);
        int r = 1 + heightOf(node->right);
        return max(l, r);
    }
};
