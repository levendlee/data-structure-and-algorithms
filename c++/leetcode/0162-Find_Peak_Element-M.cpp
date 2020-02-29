// 162 Find Peak Element
// https://leetcode.com/problems/find-peak-element

// version: 1; create time: 2020-01-30 22:36:34;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
