// 72 Edit Distance
// https://leetcode.com/problems/edit-distance

// version: 1; create time: 2020-01-29 21:26:13;
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1 == word2) return 0;
        const int m = word1.size();
        const int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // replace, insert, delete
                    dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

// 2023/11/02

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n1 = word1.size(), n2 = word2.size();

         vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MAX - 1));
         dp[0][0] = 0;

         for (int i = 0; i <= n1; ++i) {
             dp[i][0] = i;
         }
         for (int j = 0; j <= n2; ++j) {
             dp[0][j] = j;
         }

         for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                dp[i][j] = min({dp[i-1][j-1] + (word1[i-1] != word2[j-1]), dp[i-1][j] + 1, dp[i][j-1] + 1});
            }
         }
         return dp[n1][n2];
    }
};
