class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_counter = 1;
        for (const auto& n : nums_set) {
            if (nums_set.find(n - 1) == nums_set.end()) {
                int seq = n;
                int counter = 0;
                while(nums_set.find(seq++) != nums_set.end())
                {
                    counter++;
                }
                if (counter > max_counter) {
                    max_counter = counter;
                }
            }
        }
        return max_counter;
    }
};