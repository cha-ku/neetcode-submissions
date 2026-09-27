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
    bool isValidBST(TreeNode* root, int lowest=INT_MIN, int highest=INT_MAX) {
        if (!root) { return true; }
        if (root->val <= lowest || root->val >= highest ) {
            return false;
        }
        return isValidBST(root->left, lowest, root->val) && isValidBST(root->right, root->val, highest);
    }
};
