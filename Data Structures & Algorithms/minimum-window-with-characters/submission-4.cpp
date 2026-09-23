using T = unordered_map<char, int>;
class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<char, int> tMap;
        for (const auto c : t) {
            tMap[c]++;
        }
        int left = 0;
        int right = 0;
        unordered_map<char, int> window;
        int resLen = INT_MAX;
        int have = 0;
        int need = tMap.size();
        std::pair<int, int> indices{-1, -1};
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            window[c]++;
            if (tMap.contains(c) && window[c] == tMap[c]) {
                have++;
            }
            while (have == need) {
                if (right - left + 1 < resLen) {
                    resLen = right - left + 1;
                    indices = {left, right};
                }
                window[s[left]]--;
                if (tMap.contains(s[left]) && window[s[left]] < tMap[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(indices.first, resLen);
    }
};
