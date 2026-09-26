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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) { return {}; }
        vector<int> result;
        std::queue<TreeNode*> levels;
        levels.push(root);
        while(!levels.empty()) {
            int n = levels.size();
            while (n--) {
                auto tmp = levels.front();
                levels.pop();
                if (tmp->left) {
                    levels.push(tmp->left);
                }
                if (tmp->right) {
                    levels.push(tmp->right);
                }
                if (n == 0) {
                    result.push_back(tmp->val);
                }
            }
        }
        return result;
    }
};