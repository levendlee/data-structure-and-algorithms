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