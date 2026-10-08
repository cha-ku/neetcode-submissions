class Solution {
    void dfs(unordered_map<char, string>& pad, string& digits, int idx, string& subset, vector<string>& result) {
        if (subset.size() == digits.size()) {
            result.push_back(subset);
            return;
        }
        if (idx > digits.size()) {
            return;
        }
        char digit = digits[idx];
        string choices = pad[digit];
        for (int i = 0; i < choices.size(); ++i) {
            subset.push_back(choices[i]);
            dfs(pad, digits, idx+1, subset, result);
            subset.pop_back();
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) { return result; }
        unordered_map<char, string> keypad = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                              {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                              {'8', "tuv"}, {'9', "wxyz"}};
        string subset;
        dfs(keypad, digits, 0, subset, result);
        return result;
    }
};
