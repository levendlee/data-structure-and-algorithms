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