class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        vector<vector<int>> max_subarr_l(n, vector<int>(2, 0));
        int cur_max_sum = 0; int cur_max_start = 0;
        for (int i = 0; i + k <= n; ++i) {
            int cur_sum = sums[i+k] - sums[i];
            if (cur_sum > cur_max_sum) {
                cur_max_sum = cur_sum;
                cur_max_start = i;
            }
            max_subarr_l[i+k-1] = {cur_max_sum, cur_max_start};
        }

        vector<vector<int>> max_subarr_r(n, vector<int>(2, 0));
        cur_max_sum = 0; cur_max_start = 0;
        for (int i = n - 1; i >= k - 1; --i) {
            int cur_sum = sums[i+1] - sums[i-k+1];
            if (cur_sum >= cur_max_sum) {
                cur_max_sum = cur_sum;
                cur_max_start = i - k + 1;
            }
            max_subarr_r[i-k+1] = {cur_max_sum, cur_max_start};
        }

        cur_max_sum = 0;
        vector<int> cur_max_start3;
        for (int i = k; i + 2 * k <= n; ++i) {
            int cur_sum = max_subarr_l[i-1][0] + (sums[i+k] - sums[i]) + max_subarr_r[i+k][0];
            if (cur_sum > cur_max_sum) {
                cur_max_sum = cur_sum;
                cur_max_start3 = {max_subarr_l[i-1][1], i, max_subarr_r[i+k][1]};
            }
        }

        return cur_max_start3;
    }
};