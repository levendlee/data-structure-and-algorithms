class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        const int n = nums.size();
        long long res = 0;
        int rem_k_sum = 0;

        std::unordered_map<int, int> rem_k_sum_rem_cnt(n);
        rem_k_sum_rem_cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            rem_k_sum += nums[i] % modulo == k;
            int rem_k_sum_rem = rem_k_sum % modulo;
            int prev_rem_k_sum_rem = (rem_k_sum_rem - k + modulo) % modulo;
            res += rem_k_sum_rem_cnt[prev_rem_k_sum_rem];
            ++rem_k_sum_rem_cnt[rem_k_sum_rem];
        }
        return res;
    }
};
