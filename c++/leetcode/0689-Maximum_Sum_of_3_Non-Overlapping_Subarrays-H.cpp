// 689 Maximum Sum of 3 Non-Overlapping Subarrays
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays

// version: 1; create time: 2020-02-06 22:03:53;
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

//

struct Subarray {
    int i;
    int j;
    int k;
    int sum;

    Subarray(int sum = 0, int i = -1, int j = -1, int k = -1) : i(i), j(j), k(k), sum(sum) {}

    bool operator>(const Subarray& sa) const {
        return sum > sa.sum || sum == sa.sum && (i < sa.i || i == sa.i && (j < sa.j || j == sa.i && k < sa.k));
    }
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();

        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        vector<vector<Subarray>> dp(3, vector<Subarray>(n));
        for (int i = 0; i < n; ++i) {
            // Update subarray boundle 3
            // Not include
            if (i >= 1) {
                dp[2][i] = dp[2][i - 1];
            }
            // Include
            if (i >= k){
                auto nsa = dp[1][i - k];
                nsa.k = i - k + 1;
                nsa.sum += sums[i + 1] - sums[i + 1 - k];

                if (nsa > dp[2][i]) {
                    dp[2][i] = nsa;
                }
            }

            // Update subarray boundle 2
            // Not include
            if (i >= 1) {
                dp[1][i] = dp[1][i - 1];
            }
            // Include
            if (i >= k){
                auto nsa = dp[0][i - k];
                nsa.j = i - k + 1;
                nsa.sum += sums[i + 1] - sums[i + 1 - k];

                if (nsa > dp[1][i]) {
                    dp[1][i] = nsa;
                }
            }

            // Update subarray boundle 0
            // Not include
            if (i >= 1) {
                dp[0][i] = dp[0][i - 1];
            }
            // Include
            if (i >= k - 1){
                auto nsa = Subarray(sums[i + 1] - sums[i + 1 - k], i - k + 1);
                if (nsa > dp[0][i]) {
                    dp[0][i] = nsa;
                }
            }
        }

        return {dp[2][n - 1].i, dp[2][n - 1].j, dp[2][n - 1].k};
    }
};
