class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int n = nums.size();

        int subarrays = 0;
        int i = 0, j = 0, prod = nums[0];
        while (i < n) {
            if (j < i) {
                j = i;
                prod = nums[i];
            }
            while (j + 1 < n && prod * nums[j + 1] < k) {
                prod *= nums[++j];
            }
            if (prod < k) {
                subarrays += j - i + 1;
            }
            prod /= nums[i++]; 
        }

        return subarrays;
    }
};
