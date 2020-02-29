// 818 Race Car
// https://leetcode.com/problems/race-car

// version: 1; create time: 2019-10-30 22:23:33;
class Solution {
public:

    int racecar(int target) {
        if (target == 0) return 0;

        std::vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0; dp[1] = 1;

        int k = 1;
        for (int i = 1; i <= target; ++i) {
            if (i == (1 << k) - 1) {
                dp[i] = k;
                ++k;
            } else {
                // Move k-1 steps. Reset. Move back j steps. Move forward again.
                for (int j = 0; j < k - 1; ++j) {
                    dp[i] = std::min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
                }
                // Move k steps. Reset. Move backward.
                dp[i] = std::min(dp[i], dp[(1 << k) - 1 - i] + k + 1);
            }
        }

        return dp[target];
    }
};
