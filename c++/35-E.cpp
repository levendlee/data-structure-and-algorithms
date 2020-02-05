class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid;
            } else {
                return mid;
            }

        }
        return nums[lo] < target ? lo + 1 : lo;
    }
};