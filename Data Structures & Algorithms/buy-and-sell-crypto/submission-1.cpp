class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int init = 0;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            init = prices[i];
            int profit = 0;
            for (int j = i+1; j < prices.size(); ++j) {
                if (prices[j] < init) {
                    init = prices[j];
                }
                else {
                    profit = prices[j] - prices[i];
                    max_profit = std::max(profit, max_profit);
                }
            }
        }
        return max_profit;
    }
};
