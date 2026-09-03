class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for (const auto& num : nums) {
            if (counts.find(num) != counts.end()) {
                counts[num] += 1;
            }
            else {
                counts[num] = 1;
            }
        }
        std::vector<std::pair<int, int>> key_vals;
        for (const auto& [key, value] : counts) {
            key_vals.push_back(std::make_pair(key, value));
        }
        std::sort(key_vals.begin(), key_vals.end(), [](const std::pair<int, int>& kv1, const std::pair<int, int>& kv2) {
            return kv1.second > kv2.second;
        });
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(key_vals[i].first);
        }
        return result;
    }
};
