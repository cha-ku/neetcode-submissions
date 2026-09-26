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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) { return {}; }
        vector<vector<int>> res;
        std::queue<TreeNode*> seen;
        seen.push(root);
        while (!seen.empty()) {
            int k = seen.size();
            vector<int> lvl;
            lvl.reserve(k);
            while (k--) {
                auto tmp = seen.front();
                if (tmp->left) {
                    seen.push(tmp->left);
                }
                if (tmp->right) {
                    seen.push(tmp->right);
                }
                seen.pop();
                lvl.push_back(tmp->val);
            }
            res.push_back(lvl);
        }
        return res;
    }
};
