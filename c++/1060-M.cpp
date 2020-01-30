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