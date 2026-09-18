class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi = *std::max_element(piles.begin(), piles.end());
        int low = 1;
        int rate = hi;

        while (low <= hi) {
            int mid = low + (hi - low)/2;
            int local_hrs = 0;
            for (const auto& pile: piles) {
                local_hrs += std::ceil(static_cast<double>(pile)/mid);
            }
            if (local_hrs <= h) {
                rate = std::min(rate, mid);
                hi = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return rate;
    }
};
