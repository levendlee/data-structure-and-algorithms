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
