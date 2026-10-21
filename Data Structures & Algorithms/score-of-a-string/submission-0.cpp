class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for (int i = 1; i < s.size(); ++i) {
            int prev = static_cast<int>(s[i-1]);
            int curr = static_cast<int>(s[i]);
            result += abs(prev - curr);
        }
        return result;
    }
};