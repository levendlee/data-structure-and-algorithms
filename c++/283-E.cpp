class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int ridx = 0, widx = 0;
        while (ridx < n) {
            if (nums[ridx]) {
                nums[widx++] = nums[ridx];
            }
            ++ridx;
        }
        while (widx < n) {
            nums[widx++] = 0;
        }
    }
};