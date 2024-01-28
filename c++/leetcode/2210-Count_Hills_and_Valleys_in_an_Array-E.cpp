class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int status = -1; // 0 for increasing; 1 for decreasing.
        int n = nums.size();
        int changes = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                if (status == 1) ++changes;
                status = 0;
            }
            if (nums[i] < nums[i - 1]) {
                if (status == 0) ++changes;
                status = 1;
            }
        }
        return changes;
    }
};