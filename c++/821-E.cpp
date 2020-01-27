class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        const int n = S.size();

        vector<int> dp(n, 0);
        int pre_idx = 2 * n;
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) pre_idx = i;
            dp[i] = pre_idx - i;
        }
        pre_idx = - n;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) pre_idx = i;
            dp[i] = std::min(dp[i], i - pre_idx);
        }
        return dp;
    }
};