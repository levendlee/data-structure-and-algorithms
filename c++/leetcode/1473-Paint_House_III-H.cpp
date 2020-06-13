class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<int> data(m * n * target, INT_MAX);
        auto dp = [&](int i, int j, int k) ->int&{
            return data[i * n * target + k * n + j];
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < target; ++k) {
                    int prev;
                    if (i == 0) {
                        prev = 0;
                        if (k != 0) continue;
                    } else {
                        // same color
                        prev = dp(i - 1, j, k);
                        // different color
                        if (k != 0) {
                            for (int t = 0; t < n; ++t) {
                                if (t != j) {
                                    prev = min(prev, dp(i - 1, t, k - 1));
                                }
                            }
                        }
                    }
                    if (houses[i] == 0) {
                        dp(i, j, k) = prev == INT_MAX ? INT_MAX : prev + cost[i][j];
                    } else if (houses[i] - 1 == j) {
                        dp(i, j, k) = prev == INT_MAX ? INT_MAX : prev;
                    } else {
                        dp(i, j, k) = INT_MAX;
                    }
                }
            }
        }
        
        auto res = *min_element(&dp(m - 1, 0, target-1), &dp(m - 1, n, target-1));
        return res == INT_MAX ? -1 : res;   
    }
};
