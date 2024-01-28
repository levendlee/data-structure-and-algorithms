class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long max_sum = 0;
        long long sum = 0;

        unordered_map<int, int> freq;
        int uniq_count = 0;

        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ++freq[nums[i]];
            sum += nums[i];
            uniq_count += freq[nums[i]] == 1;
            if (i >= k) {
                --freq[nums[i - k]];
                sum -= nums[i - k];
                uniq_count -= freq[nums[i - k]] == 0;
            }
            if (uniq_count == k) {
                max_sum = max(max_sum, sum);
            }
        }

        return max_sum;
    }
};