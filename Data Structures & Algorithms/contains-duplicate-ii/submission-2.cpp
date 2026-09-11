class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int last = nums.size()-1;
        for (int l = 0; l < nums.size(); ++l) {
            int r = std::min(l+k, last);
            int i = l+1;
            while (i <= r) {
                if (nums[l] == nums[i]) {
                    return true;
                }
                i++;
            }
        }
        return false;
    }
};