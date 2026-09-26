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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
    }

    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;
        int count = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal, node->val);
        int l = 0, r = 0;
        if (node->left) {
            l = dfs(node->left, maxVal);
        }
        if (node->right) {
            r = dfs(node->right, maxVal);
        }
        return count + l + r;
    }
};