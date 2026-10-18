class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int min_nums = *std::min_element(nums.begin(), nums.end());
        unordered_set<int> set_nums{nums.begin(), nums.end()};
        for (int i = min_nums; i < (min_nums + nums.size()); ++i) {
            if (!set_nums.contains(i)) {
                return false;
            }
        }
        return true;
    }
};
