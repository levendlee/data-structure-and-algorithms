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