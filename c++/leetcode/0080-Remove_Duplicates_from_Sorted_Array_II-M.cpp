class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            nums[i++] = nums[j++];
            if (j < n && nums[j - 1] == nums[j]) {
                nums[i++] = nums[j++];
            }
            while (j < n && nums[j - 1] == nums[j]) {
                ++j;
            }
        }
        return i;
    }
};
