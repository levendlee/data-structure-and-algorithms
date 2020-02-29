// 727 Minimum Window Subsequence
// https://leetcode.com/problems/minimum-window-subsequence

// version: 2; create time: 2020-02-18 00:30:10;
class Solution {
public:
    string minWindow(string S, string T) {
        const int n = S.size();
        const int m = T.size();
        if (n == 0 || m == 0) return "";

        vector<int> dp(m + 1, INT_MAX);
        dp[0] = 0;
        string res;
        auto add1 = [](int num) {
            return num == INT_MAX ? num : num + 1;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) {
                if (S[i] == T[j]) {
                    dp[j+1] = min(add1(dp[j+1]), add1(dp[j]));
                } else {
                    dp[j+1] = add1(dp[j+1]);
                }
            }
            if ((dp[m] != INT_MAX) && (res.empty() || dp[m] < res.size())) {
                res = S.substr(i - dp[m] + 1, dp[m]);
            }
        }

        return res;
    }
};


// version: 1; create time: 2019-10-20 17:16:44;
class Solution {
public:
    string minWindow(string S, string T) {
        const int m = S.size();
        const int n = T.size();
        if (m < n) return "";

        std::vector<int> dp(n, -1);
        std::string res;
        for (int i = 0; i < m; ++i) {
            for (int j = n-1; j >0; --j) {
                if (S[i] == T[j]) {
                    dp[j] = std::max(dp[j], dp[j-1]);
                }
            }
            if (S[i] == T[0]) {
                dp[0] = i;
            }
            if ((S[i] == T[n-1]) && (dp[n-1] != -1)) {
                int size = i - dp[n-1] + 1;
                if (res.empty() || (size < res.size())) {
                    res = S.substr(dp[n-1], size);
                }
            }
        }

        return res;
    }
};
