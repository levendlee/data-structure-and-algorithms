// 325 Maximum Size Subarray Sum Equals k
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k

// version: 1; create time: 2020-01-25 17:51:00;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        const int n = nums.size();

        unordered_map<int, int> sums;
        sums[0] = -1;

        int len = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sums.count(sum - k)) {
                len = std::max(len, i - sums[sum - k]);
            }
            if (!sums.count(sum)) {
                sums[sum] = i;
            }
        }

        return len;
    }
};
