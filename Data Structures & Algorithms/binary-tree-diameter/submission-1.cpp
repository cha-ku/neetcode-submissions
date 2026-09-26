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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = maxHeight(root->left);
        int r = maxHeight(root->right);
        int diam = l + r;
        int sub = std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return std::max(diam, sub);
    }

    auto maxHeight(TreeNode* node) -> int {
        if (!node) return 0;
        return 1 + std::max(maxHeight(node->left), maxHeight(node->right));
    };
};
