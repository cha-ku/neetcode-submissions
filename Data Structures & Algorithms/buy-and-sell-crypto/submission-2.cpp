class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int l = 0;
        int r = 1;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                max_profit = std::max(max_profit, prices[r] - prices[l]);
            }
            else {
                l = r;
            }
            ++r;
        }
        return max_profit;
    }
};
