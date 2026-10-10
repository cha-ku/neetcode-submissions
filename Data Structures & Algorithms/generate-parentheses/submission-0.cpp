class Solution {
    void dfs(int n, string& test, int open, int closed, vector<string>& result) {
        if (open == n && closed == n) {
            result.push_back(test);
            return;
        }
        if (open < n) {
            test += "(";
            dfs(n, test, open+1, closed, result);
            test.pop_back();
        }
        if (closed < open) {
            test += ")";
            dfs(n, test, open, closed+1, result);
            test.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string test;
        dfs(n, test, 0, 0, result);
        return result;
    }
};
