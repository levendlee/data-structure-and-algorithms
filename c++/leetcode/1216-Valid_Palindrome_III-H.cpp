// 1216 Valid Palindrome III
// https://leetcode.com/problems/valid-palindrome-iii

// version: 1; create time: 2020-02-06 21:15:25;
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int size = 2; size <= n; ++size) {
            for (int i = 0; i + size <= n; ++i) {
                int j = i + size - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return n - dp[0][n-1] <= k;
    }
};

//

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        const int n = s.size();

        /*
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int d = 1; d <= n; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                int j = i + d - 1;
                dp[i][j] = (s[i] == s[j]) && (d <= 2 || dp[i + 1][j - 1]);
            }
        }
        for (int ik = 1; ik <= k; ++ik) {
            vector<vector<bool>> ndp = dp;
            for (int d = 1; d <= n; ++d) {
                for (int i = 0; i <= n - d; ++i) {
                    int j = i + d - 1;
                    ndp[i][j] = d <= 1 || dp[i][j] || dp[i + 1][j] || dp[i][j - 1] || (s[i] == s[j]) && ndp[i + 1][j - 1];
                }
            }
            dp = move(ndp);
        }
        */

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int d = 2; d <= n; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                int j = i + d - 1;
                dp[i][j] = d;
                if (s[i] == s[j]) {
                    dp[i][j] = min(dp[i][j], d <= 2 ? 0 : dp[i + 1][j - 1]);
                }
                dp[i][j] = min({dp[i][j], dp[i + 1][j] + 1, dp[i][j - 1] + 1});
            }
        }

        return dp[0][n - 1] <= k;
    }
};
