// 730 Count Different Palindromic Subsequences
// https://leetcode.com/problems/count-different-palindromic-subsequences

// version: 1; create time: 2020-02-10 13:04:05;
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        const int n = S.size();
        int mod = pow(10, 9) + 7;

        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int size = 1; size <= n; ++size) {
            for (int i = 0; i + size <= n; ++i) {
                int j = i + size - 1;
                for (int k = 0; k < 4; ++k) {
                    const char c = k + 'a';
                    if (S[i] != c && S[j] != c) {
                        dp[k][i][j] = (i + 1 < n && j - 1 >= 0) ? dp[k][i+1][j-1] : 0;
                    } else if (S[i] != c) {
                        dp[k][i][j] = (i + 1 <  n) ? dp[k][i+1][j] : 0;
                    } else if (S[j] != c) {
                        dp[k][i][j] = (j - 1 >= 0) ? dp[k][i][j-1] : 0;
                    } else {
                        if (i == j) {
                            dp[k][i][j] = 1;
                        } else if (i + 1 >= n || j - 1 < 0) {
                            dp[k][i][j] = 2;
                        } else {
                            auto tmp = 2L + dp[0][i+1][j-1] + dp[1][i+1][j-1] + dp[2][i+1][j-1] + dp[3][i+1][j-1];
                            dp[k][i][j] = tmp % mod;
                        }
                    }
                    dp[k][i][j] %= mod;
                }
            }
        }

        long cnt = 0;
        for (int k = 0; k < 4; ++k) {
            cnt += dp[k][0][n-1];
        }
        return cnt % mod;
    }
};
