class Solution {
    void dfs(int start, vector<int>& nums, vector<int>& subset, int target, vector<vector<int>>& result) {
        int acc = std::accumulate(subset.begin(), subset.end(), 0);
        if (acc == target) {
            result.push_back(subset);
            return;
        }
        if (acc > target) {
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            dfs(i, nums, subset, target, result);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(0, nums, subset, target, result);
        return result;
    }
};
