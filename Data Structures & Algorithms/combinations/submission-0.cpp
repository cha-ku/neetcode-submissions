class Solution {
    void dfs(vector<vector<int>>& result, vector<int>& subset, int n, int k, int i) {
        if (subset.size() == k) {
            result.push_back(subset);
            return;
        }
        if (i > n) {
            return;
        }
        for (int j = i; j <= n; ++j) {
            subset.push_back(j);
            dfs(result, subset, n, k, j+1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(result, subset, n, k, 1);
        return result;
    }
};