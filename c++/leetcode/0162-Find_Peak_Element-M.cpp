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

//
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return 0;

        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int left_increase = mid - 1 < 0 || nums[mid - 1] < nums[mid];
            int right_decrease = mid + 1 >= n || nums[mid + 1] < nums[mid];
            if (left_increase && right_decrease) {
                return mid;
            } else if (left_increase && !right_decrease) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return 0;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return 0;

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
