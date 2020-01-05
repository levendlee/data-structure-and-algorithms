class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        const int n = costs.size();
        if (n == 0) return 0;
        const int k = costs[0].size();
        if (k == 0) return 0;

        if (n == 1 && k == 1) return costs[0][0];

        vector<int> dp(k, 0);
        array<int, 2> min2 = {0,1};  // {min_color, min2_color}

        for (int i = 0; i < n; ++i) {
            vector<int> new_dp(k, 0);
            array<int, 2> new_min2 = {-1, -1};
            for (int j = 0; j < k; ++j) {
                if (min2[0] != j) {
                    new_dp[j] = dp[min2[0]] + costs[i][j];
                } else {
                    new_dp[j] = dp[min2[1]] + costs[i][j];
                }
                if (new_min2[0] == -1 || new_dp[j] <= new_dp[new_min2[0]]) {
                    new_min2[1] = new_min2[0];
                    new_min2[0] = j;
                } else if (new_min2[1] == -1 || new_dp[j] <= new_dp[new_min2[1]]) {
                    new_min2[1] = j;
                }
            }
            dp = std::move(new_dp);
            min2 = std::move(new_min2);
        }

        return *std::min_element(dp.begin(), dp.end());
    }
};