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