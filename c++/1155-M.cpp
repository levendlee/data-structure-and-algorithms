class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target, 0);
        for (int i = 0; i < std::min(f, target); ++i) {
            dp[i] = 1;
        }
        constexpr long base = pow(10, 9) + 7;
        for (int num = 2; num <= d; ++num) {
            vector<int> ndp(target, 0);
            for (int sum = num; sum <= target; ++sum) {
                for (int k = 1; k <= std::min(f, sum-1) ; ++k) {
                    ndp[sum-1] = (ndp[sum-1] + dp[sum-k-1]) % base;
                }
            }
            dp = std::move(ndp);
        }
        return dp[target-1];
    }
};