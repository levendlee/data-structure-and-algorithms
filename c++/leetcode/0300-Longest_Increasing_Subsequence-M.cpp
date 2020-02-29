// 300 Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence

// version: 1; create time: 2019-11-14 23:06:23;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (auto& n : nums) {
            auto idx = std::upper_bound(dp.begin(), dp.end(), n) - dp.begin();
            if (idx == 0 || dp[idx - 1] < n) {
                if (idx == dp.size()) {
                    dp.push_back(n);
                } else {
                    dp[idx] = n;
                }
            }
        }
        return dp.size();
    }
};
