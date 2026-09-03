class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        return std::unordered_set<int>{nums.cbegin(), nums.cend()}.size() != nums.size();
    }
};