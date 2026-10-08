class Solution {
    void dfs(vector<int>& n, vector<vector<int>>& result, vector<int>& sub, int i) {
        if (i >= n.size()) {
            result.push_back(sub);
            return;
        }
        sub.push_back(n[i]);
        dfs(n, result, sub, i+1);
        sub.pop_back();
        while (i+1 < n.size() && n[i] == n[i+1]) {
            ++i;
        }
        dfs(n, result, sub, i+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, result, subset, 0);
        return result;
    }
};
