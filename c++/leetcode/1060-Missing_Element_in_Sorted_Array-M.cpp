// 1060 Missing Element in Sorted Array
// https://leetcode.com/problems/missing-element-in-sorted-array

// version: 1; create time: 2020-01-29 23:14:02;
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n == 1) return nums[0] + k;

        int lo = 0, hi = n - 1;
        int min_idx = INT_MAX, max_idx = INT_MIN;
        while (lo < hi) {
            const int mid = lo + (hi - lo) / 2;
            const int missing = nums[mid] - nums[0] - mid;
            if (missing <= k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        int idx = lo;
        int missing = nums[idx] - nums[0] - idx;
        while (missing >= k) {
            --idx;
            missing = nums[idx] - nums[0] - idx;
        }
        return nums[idx] + k - missing;
    }
};

..

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        const int n = nums.size();
        int lo = 0, hi = n;
        auto get_missing = [&](int i) {
            return nums[i] - nums[0] - i;
        };

        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            int pre_missing = mid == 0 ? 0 : get_missing(mid - 1);
            int cur_missing = mid == n ? pre_missing : get_missing(mid);
            if (cur_missing < k) {
                lo = mid;
            } else if (pre_missing >= k) {
                hi = mid - 1;
            } else {
                return nums[mid - 1] + k - pre_missing;
            }
        }
        return nums[n - 1] + k - get_missing(n - 1);
    }
};
