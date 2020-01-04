class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        const auto getNumber = [&](const int& i) {
            return i < 0 || i >= n ? 1 : nums[i];
        };

        for (int m = 1; m <= n; ++m) {
            for (int i = 0; i + m <= n; ++i) {
                int j = i + m - 1;
                dp[i+1][j+1] = 0;
                for (int k = i; k <= j; ++k) {
                    dp[i+1][j+1] = std::max(dp[i+1][j+1], dp[i+1][k] + dp[k+2][j+1] + getNumber(i-1) * nums[k] * getNumber(j+1));
                }
            }
        }

        return dp[1][n];
    }
};