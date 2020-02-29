// 115 Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences

// version: 1; create time: 2020-01-26 17:39:50;
class Solution {
public:
    int numDistinct(string s, string t) {
        const int m = s.size();
        const int n = t.size();
        if (m < n) return 0;

        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = n; j > 0; --j) {
                //if (dp[j-1] == 0) continue;
                if (s[i] == t[j-1]) dp[j] += dp[j-1];
            }
        }
        return dp[n];
    }
};
