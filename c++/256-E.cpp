class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        const int m = costs.size();
        if (m == 0) return 0;
        auto dp = costs[0], ndp = dp;
        for (int i = 1; i < m; ++i) {
            ndp[0] = min(dp[1], dp[2]) + costs[i][0];
            ndp[1] = min(dp[0], dp[2]) + costs[i][1];
            ndp[2] = min(dp[0], dp[1]) + costs[i][2];
            std::swap(dp, ndp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};