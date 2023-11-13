// 1143 Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence

// version: 1; create time: 2020-02-01 17:20:17;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.size();
        const int n = text2.size();
        vector<int> dp(n + 1, 0);
        vector<int> longest(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j+1] = std::max(dp[j+1], longest[j+1] + (text1[i] == text2[j]));
            }
            for (int j = 0; j < n; ++j) {
                longest[j+1] = std::max(longest[j], dp[j]);
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

//

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n1 = text1.size(), n2 = text2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                dp[i + 1][j + 1] = max({dp[i + 1][j], dp[i][j + 1], dp[i][j] + (text1[i] == text2[j])});
            }
        }

        return dp[n1][n2];
    }
};
