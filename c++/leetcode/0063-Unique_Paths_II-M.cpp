// 63 Unique Paths II
// https://leetcode.com/problems/unique-paths-ii

// version: 1; create time: 2020-02-01 20:24:17;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        if (m == 0) return 0;
        const int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;

        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[1][1] = 1;
        //obstacleGrid[0][0] = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) continue;
                /*
                const auto up = i == 0 ? 0 : (obstacleGrid[i-1][j] == 1 ? 0 : -obstacleGrid[i-1][j]);
                const auto left = j == 0 ? 0 : (obstacleGrid[i][j-1] == 1 ? 0 : -obstacleGrid[i][j-1]);
                obstacleGrid[i][j] = -(up + left);
                */
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
            }
        }

        //return -obstacleGrid[m-1][n-1];
        return dp[m][n];
    }
};
