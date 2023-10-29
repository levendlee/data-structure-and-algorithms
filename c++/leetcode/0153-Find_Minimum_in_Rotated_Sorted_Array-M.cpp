// 153 Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

// version: 1; create time: 2020-02-01 21:00:52;
class Solution {
public:
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= nums[0]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return std::min(nums[0], nums[lo]);
    }
};

// 2023/10/28

class Solution {
public:
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        if (nums.size() == 1 || nums[0] < nums[n - 1]) return nums[0];

        int lo = 1, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[0] < nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};
