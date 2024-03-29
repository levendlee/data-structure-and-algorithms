// 283 Move Zeroes
// https://leetcode.com/problems/move-zeroes

// version: 1; create time: 2020-02-01 23:45:57;
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

//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j]) {
                nums[i++] = nums[j];
            }
            ++j;
        }
        while (i < n) {
            nums[i++] = 0;
        }
    }
};
