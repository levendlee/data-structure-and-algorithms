class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return false;

        for (const int num : nums) {
            int idx = abs(num) - 1;
            if (idx > n - 1 || nums[idx] < 0 && idx != n - 2) {
                return false;
            }
            nums[idx] *= -1; 
        }
        return nums[n - 2] > 0;
    }
};
