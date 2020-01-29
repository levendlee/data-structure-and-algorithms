class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int m = dungeon.size();
        if (m == 0) return 0;
        const int n = dungeon[0].size();
        if (n == 0) return 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX / 2));
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = std::max(-dungeon[i][j] + 1, 1);
                    continue;
                }
                dp[i][j] = std::min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = std::max(dp[i][j], std::max(-dungeon[i][j] + 1, 1));
            }
        }

        return dp[0][0];
    }
};