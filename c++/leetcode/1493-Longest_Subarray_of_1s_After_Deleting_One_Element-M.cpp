class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();

        int longest = 0;
        int i = 0, j = 0, num_zeros = 0;
        while (j < n) {
            num_zeros += nums[j++] == 0;
            while (num_zeros > 1) {
                num_zeros -= nums[i++] == 0;
            }
            longest = max(longest, j - i - 1);
        }
        return longest;
    }
};
