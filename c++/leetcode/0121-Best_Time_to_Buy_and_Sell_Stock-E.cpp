// 121 Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

// version: 1; create time: 2020-01-08 23:19:38;
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

// 2023/11/04

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int lowest_price = INT_MAX;
        for (int p : prices) {
            max_profit = max(max_profit, p - lowest_price);
            lowest_price = min(lowest_price, p);
        }
        return max_profit;
    }
};
