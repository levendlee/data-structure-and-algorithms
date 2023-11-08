class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n < k) return 0.0;

        int i = 0, j = k;
        int sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        int max_sum = sum;
        while (j < n) {
            sum += nums[j++];
            sum -= nums[i++]; 
            max_sum = max(max_sum, sum);
        }
        return max_sum * 1.0 / k;
    }
};
