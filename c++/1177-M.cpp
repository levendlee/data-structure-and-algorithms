class Solution {
public:
    bool canMakePalindrome(const vector<vector<int>>& dp, vector<int>& query) {
        const int i = query[0];
        const int j = query[1];
        int rem = 0;
        for (int t = 0; t < 26; ++t) {
            rem += (dp[j+1][t] - dp[i][t]) % 2;
        }
        const int k = query[2];
        rem -= (j - i + 1) % 2;
        return rem <= 2 * k;
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        const int m = s.size();
        const int n = queries.size();

        vector<vector<int>> dp(m + 1, vector<int>(26, 0));
        for (int i = 0; i < m; ++i) {
            dp[i+1] = dp[i];
            ++dp[i+1][s[i] - 'a'];
        }

        vector<bool> res(n, false);
        for (int i = 0; i < n; ++i) {
            res[i] = canMakePalindrome(dp, queries[i]);
        }
        return res;
    }
};