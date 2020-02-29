// 320 Generalized Abbreviation
// https://leetcode.com/problems/generalized-abbreviation

// version: 1; create time: 2020-01-18 21:31:05;
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        const int n = word.size();
        if (n == 0) return {""};
        vector<vector<string>> dp(n);
        dp[0] = {word.substr(0, 1), "1"};
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (auto& abbr : dp[j]) {
                    if (!isdigit(abbr.back())) {
                        dp[i].push_back(abbr + to_string(i - j));
                    }
                }
            }
            for (auto& abbr : dp[i-1]) {
                dp[i].push_back(abbr + word[i]);
            }
            dp[i].push_back(to_string(i + 1));
        }
        return dp[n-1];
    }
};
