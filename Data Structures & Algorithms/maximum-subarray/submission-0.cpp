class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int curr_sum = 0;
        for (const auto& n : nums) {
            curr_sum = std::max(curr_sum, 0);
            curr_sum += n;
            max_sum = std::max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
