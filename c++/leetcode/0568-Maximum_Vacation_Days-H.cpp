// 568 Maximum Vacation Days
// https://leetcode.com/problems/maximum-vacation-days

// version: 1; create time: 2020-02-06 22:19:17;
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        const int n = flights.size();
        const int k = days[0].size();
        vector<int> dp(n, INT_MIN), ndp(n, INT_MIN);
        dp[0] = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                ndp[j] = dp[j];
                for (int t = 0; t < n; ++t) {
                    if (flights[t][j]) {
                        ndp[j] = std::max(ndp[j], dp[t]);
                    }
                }
                ndp[j] += days[j][i];
            }
            std::swap(dp, ndp);
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};
