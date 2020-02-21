class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int n = nums.size();
        int i = 0, j = 0, k = 0;
        for (int t = 0; t < n; ++t) {
            if (nums[t] == 0) {
                nums[k++] = 2;
                nums[j++] = 1;
                nums[i++] = 0;
            } else if (nums[t] == 1) {
                nums[k++] = 2;
                nums[j++] = 1;
            } else {
                nums[k++] = 2;
            }
        }
    }
};