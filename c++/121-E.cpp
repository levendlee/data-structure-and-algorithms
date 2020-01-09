class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = INT_MAX - 1;
        for (const auto& p : prices) {
            max_profit = std::max(max_profit, p - min_price);
            min_price = std::min(min_price, p);
        }
        return max_profit;
    }
};