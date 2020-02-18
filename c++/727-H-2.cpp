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