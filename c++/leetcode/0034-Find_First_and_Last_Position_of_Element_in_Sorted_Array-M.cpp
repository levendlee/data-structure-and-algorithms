// 34 Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

// version: 1; create time: 2020-01-27 21:52:01;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        int lo = 0, hi = n - 1, mid, start = -1, end = -1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else if (mid == 0 || nums[mid-1] < target) {
                start = mid;
                break;
            } else {
                hi = mid - 1;
            }
        }

        lo = 0, hi = n - 1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else if (mid == n - 1 || nums[mid+1] > target) {
                end = mid;
                break;
            } else {
                lo = mid + 1;
            }
        }

        return {start, end};
    }
};


// 2023/10/28
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        if (nums.empty()) return {-1, -1};

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (nums[lo] != target) return {-1, -1};

        int start = lo;
        lo = start, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        int end = lo;
        return {start, end};
    }
};
