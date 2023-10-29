// 33 Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array

// version: 1; create time: 2020-01-07 22:30:05;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int lo = 0, hi = n - 1, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[0] < nums[mid] || nums[mid] > nums[n-1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        mid = lo;
        auto iter0 = std::lower_bound(nums.begin(), nums.begin() + mid, target);
        if (iter0 != nums.begin() + mid && *iter0 == target) return iter0 - nums.begin();
        auto iter1 = std::lower_bound(nums.begin() + mid, nums.end(), target);
        if (iter1 != nums.end() && *iter1 == target) return iter1 - nums.begin();
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();

        int start = 0;
        if (nums[0] < nums[n - 1]) {
            start = 0;
        } else {
            int lo = 1, hi = n - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (nums[0] < nums[mid]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            start = lo;
        }

        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int idx = (mid + start) % n;
            if (nums[idx] == target) {
                return idx;
            } else if (nums[idx] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};
