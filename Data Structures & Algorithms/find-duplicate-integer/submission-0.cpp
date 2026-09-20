class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (const auto& n : nums) {
            if (seen.contains(n)) {
                return n;
            }
            seen.insert(n);
        }
        return -1;
    }
};
