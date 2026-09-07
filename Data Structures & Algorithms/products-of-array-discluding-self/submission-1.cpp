class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre_num(nums.size());
        pre_num[0] = nums[0];
        vector<int> post_num(nums.size());
        int last_index = nums.size() - 1;
        post_num[last_index] = nums[last_index];
        for (int i = 1; i < nums.size(); ++i) {
            pre_num[i] = pre_num[i-1] * nums[i];
        }
        for (int i = (last_index-1); i >= 0; --i) {
            post_num[i] = post_num[i+1] * nums[i];
        }
        vector<int> result(nums.size());
        for (int i = 0; i <= last_index; ++i) {
            int pre = (i > 0) ? pre_num[i - 1] : 1;
            int post = (i < last_index) ? post_num[i + 1] : 1;
            result[i] = pre * post;
        }
        return result;
    }
};
