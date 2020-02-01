class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        const int n = nums.size();
        bool modified = false;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                if (modified) return false;
                modified = true;
                if (i - 2 < 0 || nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i];
                } else {
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};