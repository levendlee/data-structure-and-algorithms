// 209 Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum

// version: 1; create time: 2020-01-26 21:40:28;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int n = nums.size();
        int min_dist = n + 1;
        int sum = 0;
        int i = 0, j = 0;
        while (j < n) {
            sum += nums[j];
            while (i <= j && sum >= s) {
                min_dist = std::min(min_dist, j - i + 1);
                sum -= nums[i++];
            }
            ++j;
        }
        return min_dist > n ? 0 : min_dist;
    }
};
