// 410 Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum

// version: 1; create time: 2020-02-18 20:35:26;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long lo = *max_element(nums.begin(), nums.end());
        long hi = accumulate(nums.begin(), nums.end(), 0L);
        long res = INT_MAX;
        while (lo <= hi) {
            auto mid = lo + (hi - lo + 1) / 2;
            long cnt = 1, sum = 0, max_sum = 0;
            for (const auto& n : nums) {
                sum += n;
                if (sum > mid) {
                    ++cnt;
                    max_sum = max(max_sum, sum - n);
                    sum = n;
                }
            }
            max_sum = max(max_sum, sum);
            if (cnt <= m) {
                res = min(max_sum, res);
            }
            if (cnt <= m) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    }
};
