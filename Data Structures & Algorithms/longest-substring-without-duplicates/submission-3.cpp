class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        std::unordered_map<char, int> seen;
        int start = 0;
        int end = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (seen.empty()) {
                seen[c] = i;
                start = i;
                end = i;
                continue;
            }
            if (seen.contains(c)) {
                max_len = std::max(max_len, end-start+1);
                start = std::max(start, seen[c] + 1);
                end = i;
                seen[c] = i;
                continue;
            }
            seen[c] = i;
            end = i;
        }
        return std::max(max_len, end-start+1);

    }
};
