class Solution {
    void dfs(int start, vector<int>& candidates, vector<int>& sub, int target, vector<vector<int>>& res) {
        int currSum = std::accumulate(sub.begin(), sub.end(), 0);
        if (currSum == target) {
            res.push_back(sub);
            return;
        }
        if (currSum > target) {
            return;
        }
        for(int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            sub.push_back(candidates[i]);
            dfs(i+1, candidates, sub, target, res);
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> subset;//{{candidates[0]}};
        dfs(0, candidates, subset, target, result);
        return result;
    }
};
