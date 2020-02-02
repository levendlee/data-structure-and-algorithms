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