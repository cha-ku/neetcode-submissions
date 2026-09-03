class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> complements;
        for (int i = 0; i < nums.size(); ++i) {
            const int num = nums[i];
            const int complement = target - num;
            if (complements.find(complement) != complements.end()) {
                return {complements[complement], i};
            }
            complements[num] = i;
        }
        return {};
    }
};
