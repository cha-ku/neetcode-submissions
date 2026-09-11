class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int result = 0;
        long long product = 1;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            product *= nums[r];
            while(product >= k) {
                product /= nums[l++];
            }
            result += r - l + 1;
        }
        return result;
    }
};