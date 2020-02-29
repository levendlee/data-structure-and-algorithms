// 540 Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array

// version: 1; create time: 2020-02-11 18:55:15;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int n = nums.size();
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid + 1 < n && nums[mid] == nums[mid + 1]) {
                if (mid % 2) {
                    hi = mid - 1;
                } else {
                    lo = mid + 2;
                }
            } else if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (mid % 2) {
                    lo = mid + 1;
                } else {
                    hi = mid - 2;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[lo];
    }
};
