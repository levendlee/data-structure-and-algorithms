class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n; i >= 1; --i) {
            dp[i - 1] = prices[i - 1] + *min_element(dp.begin() + i, dp.begin() + min(i + i + 1, n + 1));
        }
        return dp[0];
    }
};