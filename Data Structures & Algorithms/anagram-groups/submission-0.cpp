class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& str : strs) {
            std::string copy_str = str;
            std::sort(copy_str.begin(), copy_str.end());
            if (groups.find(copy_str) != groups.end()) {
                groups[copy_str].push_back(str);
            }
            else {
                groups[copy_str] = {str};
            }
        }
        std::vector<std::vector<std::string>> result;
        for (const auto& [key, val] : groups) {
            result.push_back(val);
        }
        return result;
    }
};
