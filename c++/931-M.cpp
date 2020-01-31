class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int m = A.size();
        if (m == 0) return 0;
        const int n = A[0].size();
        if (n == 0) return 0;

        vector<int> dp = A[0];
        vector<int> ndp = dp;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ndp[j] = INT_MAX;
                if (j > 0)
                    ndp[j] = std::min(ndp[j], dp[j-1] + A[i][j]);
                ndp[j] = std::min(ndp[j], dp[j] + A[i][j]);
                if (j < n - 1)
                    ndp[j] = std::min(ndp[j], dp[j+1] + A[i][j]);
            }
            std::swap(dp, ndp);
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};