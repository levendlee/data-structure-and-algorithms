// 322 Coin Change
// https://leetcode.com/problems/coin-change

// version: 1; create time: 2020-01-11 17:33:19;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const auto& c : coins) {
                if (i - c >= 0) {
                    if (dp[i - c] == INT_MAX) continue;
                    dp[i] = std::min(dp[i], dp[i - c] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
