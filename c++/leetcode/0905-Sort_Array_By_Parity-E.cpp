class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        const int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !(nums[i] & 0x1)) ++i;
            while (i < j && (nums[j] & 0x1)) --j;
            if (i < j) std::swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};