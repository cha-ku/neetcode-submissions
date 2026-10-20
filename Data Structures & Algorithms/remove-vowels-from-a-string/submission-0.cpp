class Solution {
public:
    string removeVowels(string s) {
        string result;
        for (const char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                continue;
            }
            result.push_back(c);
        }
        return result;
    }
};
