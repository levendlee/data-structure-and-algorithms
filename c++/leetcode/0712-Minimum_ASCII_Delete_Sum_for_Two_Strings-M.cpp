// 712 Minimum ASCII Delete Sum for Two Strings
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

// version: 1; create time: 2020-02-20 21:59:32;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 0; i < n2; ++i) {
            dp[0][i+1] = dp[0][i] + s2[i];
        }
        for (int i = 0; i < n1; ++i) {
            dp[i+1][0] = dp[i][0] + s1[i];
        }
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = min(dp[i][j+1] + s1[i], dp[i+1][j] + s2[j]);
                }
            }
        }

        return dp[n1][n2];
    }
};
