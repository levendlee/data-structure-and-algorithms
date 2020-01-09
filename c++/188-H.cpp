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