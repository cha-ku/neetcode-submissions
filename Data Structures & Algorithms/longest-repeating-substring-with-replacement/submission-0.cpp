class Solution {
public:
    int characterReplacement(string s, int k) {
        std::array<int, 26> letters{};
        int result = 0;
        int l = 0;
        int max_count = 0;
        for (int r = 0; r < s.size(); ++r) {
            int c = s[r] - 'A';
            letters[c]++;
            max_count = letters[c] > max_count ? letters[c] : max_count;
            while(((r-l+1) - max_count) > k) {
                letters[s[l] - 'A']--;
                ++l;
            }
            result = std::max(result, r-l+1);
        }
        return result;
    }
};
