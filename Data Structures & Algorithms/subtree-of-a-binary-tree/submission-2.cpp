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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == subRoot) { return true; }
        if ((root && !subRoot) || (!root && subRoot)) { return false; }
        if (root->val == subRoot->val && isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* f, TreeNode* s) {
        if (!f && !s) { return true; }
        if ((f && !s) || (!f && s)) { return false; }
        if (f->val == s->val) {
            return isSameTree(f->left, s->left) && isSameTree(f->right, s->right);
        }
        return false;
    }
};
