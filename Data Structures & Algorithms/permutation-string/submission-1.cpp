class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) { return false; }

        unordered_map<char, int> s1map;
        for (auto c : s1) {
            s1map[c]++;
        }

        unordered_map<char, int> s2map;
        int k = s1.size();
        int l = 0;
        while (l < k) {
            s2map[s2[l]]++;
            ++l;
        }
        if (s1map == s2map) {
            return true;
        }

        for (int i = k; i < s2.size(); ++i) {
            char left = s2[i-k];
            if (s2map[left] == 1) {
                s2map.erase(left);
            }
            else {
                s2map[left]--;
            }
            s2map[s2[i]]++;

            if (s1map == s2map) {
                return true;
            }
        }
        return false;
    }
};