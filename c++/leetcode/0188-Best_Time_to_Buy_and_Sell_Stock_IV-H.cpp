// 188 Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

// version: 1; create time: 2020-01-08 23:49:21;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        if (k <= 0) return 0;
        if (n <= 1) return 0;

        k = std::min(k, n / 2 + 1);

        vector<int> dp(2 * k, 0);
        for (int i = 0; i < 2 * k; i += 2) {
            dp[i] = INT_MIN;
        }
        for (const auto& p : prices) {
            for (int i = 2 * k - 1; i >= 3; i -= 2) {
                dp[i] = std::max(dp[i], dp[i-1] + p);
                dp[i-1] = std::max(dp[i-1], dp[i-2] - p);
            }
            dp[1] = std::max(dp[1], dp[0] + p);
            dp[0] = std::max(dp[0], -p);
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

//

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int64_t> sell(k, INT_MIN), buy(k, INT_MIN);
        for (auto p : prices) {
            for (int i = k - 1; i >= 0; --i) {
                sell[i] = max(sell[i], buy[i] + p);
                buy[i] = max(buy[i], (i == 0 ? 0 : sell[i-1]) - p);
            }
        }
        return max(*max_element(sell.begin(), sell.end()), int64_t(0));
    }
};
