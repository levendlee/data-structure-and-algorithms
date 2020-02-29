// 44 Wildcard Matching
// https://leetcode.com/problems/wildcard-matching

// version: 1; create time: 2020-01-30 20:50:22;
class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();
        vector<int> dp(m + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            vector<int> ndp(m + 1, false);
            if (p[i] == '*') {
                int j = 0;
                while (j <= m && !dp[j]) ++j;
                while (j <= m) ndp[j++] = true;
            } else if (p[i] == '?') {
                for (int j = 0; j < m; ++j) {
                    ndp[j + 1] = dp[j];
                }
            } else {
                for (int j = 0; j < m; ++j) {
                    ndp[j + 1] = (p[i] == s[j]) && dp[j];
                }
            }
            dp = std::move(ndp);
        }
        return dp[m];
    }
};
