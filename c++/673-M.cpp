class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return n;

        vector<vector<int>> dp(n);
        int total_max_len = 0;
        int total_max_cnt = 0;
        for (int i = 0; i < n; ++i) {
            int max_len = 1;
            int max_cnt = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) continue;
                if (dp[j][0] + 1 > max_len) {
                    max_len = dp[j][0] + 1;
                    max_cnt = dp[j][1];
                } else if (dp[j][0] + 1 == max_len) {
                    max_cnt += dp[j][1];
                }
            }
            dp[i] = {max_len, max_cnt};

            if (max_len > total_max_len) {
                total_max_len = max_len;
                total_max_cnt = max_cnt;
            } else if (max_len == total_max_len) {
                total_max_cnt += max_cnt;
            }
        }

        return total_max_cnt;
    }
};