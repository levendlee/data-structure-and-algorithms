class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int size = 1; size <= n; ++size) {
            for (int i = 0; i + size <= n; ++i) {
                int j = i + size - 1;
                if (i == j) {
                    dp[i][j] = 1;
                } else if (s[i] == s[j]) {
                    dp[i][j] = 2 + (size >= 2 ? dp[i+1][j-1] : 0);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};