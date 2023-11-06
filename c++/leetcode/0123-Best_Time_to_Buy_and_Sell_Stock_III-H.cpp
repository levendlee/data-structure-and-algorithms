// 123 Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

// version: 1; create time: 2020-01-08 23:41:13;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(4, 0);
        dp[0] = INT_MIN;
        dp[2] = INT_MIN;
        for (const auto& p : prices) {
            dp[3] = std::max(dp[3], dp[2] + p); // sell stock
            dp[2] = std::max(dp[2], dp[1] - p); // buy stock
            dp[1] = std::max(dp[1], dp[0] + p); // sell stock
            dp[0] = std::max(dp[0], -p); // buy stock
        }
        return std::max(dp[1], dp[3]);
    }
};

// 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int64_t buy0 = INT_MIN, sell0 = INT_MIN, buy1 = INT_MIN, sell1 = INT_MIN;
        for (auto p : prices) {
            sell1 = max(sell1, buy1 + p);
            buy1 = max(buy1, sell0 - p);
            sell0 = max(sell0, buy0 + p);
            buy0 = max(buy0, int64_t(-p));
        }
        return max({sell0, sell1, int64_t(0)});
    }
};
