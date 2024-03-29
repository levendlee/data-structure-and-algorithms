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

// 2023/10/30
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> min_num_coins(amount + 1, INT_MAX);
        min_num_coins[0] = 0;
        for (long long i = 0; i <= amount; ++i) {
            if (min_num_coins[i] == INT_MAX) continue;
            for (int c : coins) {
                if (i + c > amount) continue;
                min_num_coins[i + c] = std::min(min_num_coins[i + c], min_num_coins[i] + 1);
            }
        }
        return min_num_coins[amount] == INT_MAX ? -1 : min_num_coins[amount];
    }
};
