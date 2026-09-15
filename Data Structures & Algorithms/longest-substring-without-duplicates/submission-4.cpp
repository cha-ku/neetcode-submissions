class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        std::unordered_map<char, int> seen;
        int start = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (seen.contains(c) && seen[c] >= start) {
                start = seen[c] + 1;
            }
            seen[c] = i;
            max_len = std::max(max_len, i-start+1);
        }
        return max_len;

    }
};
