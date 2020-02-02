class Solution {
public:
    int findMinHelper(vector<int>& nums, int start, int end) {
        if (start > end) {
            return INT_MAX;
        }
        int lo = start, hi = end;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[start] || nums[mid] == nums[start] && nums[mid] > nums[end]) {
                lo = mid + 1;
            } else if (nums[mid] < nums[start] || nums[mid] == nums[start] && nums[mid] < nums[end]) {
                hi = mid;
            } else {
                return std::min(findMinHelper(nums, lo, mid), findMinHelper(nums, mid + 1, hi));
            }
        }
        return std::min(nums[start], nums[lo]);
    }
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        return findMinHelper(nums, 0, n - 1);
    }
};