class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = *std::max_element(nums.begin(), nums.end());
        int sum = 0;
        int i = 0, j = 0, n = nums.size();
        while (j < n) {
            sum += nums[j++];
            while (sum < 0) {
                sum -= nums[i++];
            }
            if (i != j) {
                max_sum = max(sum, max_sum);
            }
            
        }
        return max_sum;
    }
};
