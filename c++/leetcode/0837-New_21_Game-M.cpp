// 837 New 21 Game
// https://leetcode.com/problems/new-21-game

// version: 1; create time: 2019-10-22 22:46:46;
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1;
        if (N < K) return 0;

        std::vector<double> dp(N + 1);
        dp[0] = 1.0;

        double sum = 1.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = sum / W;
            sum += (i < K ? dp[i] : 0) - (i >= W ? dp[i - W] : 0);
        }

        return std::accumulate(dp.begin() + K, dp.begin() + N + 1, 0.0);
    }
};
