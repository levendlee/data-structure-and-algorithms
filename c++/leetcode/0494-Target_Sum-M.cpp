// 494 Target Sum
// https://leetcode.com/problems/target-sum

// version: 1; create time: 2020-02-08 14:32:09;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int n = nums.size();

        unordered_map<int, int> sum_cnts;
        sum_cnts[0] = 1;

        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i+1] = sums[i] + nums[i];
        }

        // Use DP in [-sum, +sum]
        const auto in_range = [&](const auto& i, const auto& v) {
            long d = sums[n] - sums[i+1];
            return (v <= S + d) && (v >= S - d);
        };

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> n_sum_cnts;
            for (const auto& p : sum_cnts) {
                auto v1 = p.first - nums[i];
                if (in_range(i, v1)) {
                    n_sum_cnts[v1] += p.second;
                }
                auto v2 = p.first + nums[i];
                if (in_range(i, v2)) {
                    n_sum_cnts[v2] += p.second;
                }
            }
            if (n_sum_cnts.empty()) return 0;
            sum_cnts = std::move(n_sum_cnts);
        }

        return sum_cnts[S];
    }
};

//

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();

        unordered_map<int, int> sum2cnt;
        sum2cnt[0] = 1;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> n_sum2cnt;
            for (const auto [sum, cnt] : sum2cnt) {
                n_sum2cnt[sum + nums[i]] += cnt;
                n_sum2cnt[sum - nums[i]] += cnt;
            }
            sum2cnt = move(n_sum2cnt);
        }

        return sum2cnt[target];
    }
};

//

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target) return 0;
        if ((sum + target) & 0x1) return 0;

        int s = (sum + target) / 2;
        if (s < 0) return 0;

        vector<int> dp(s + 1, 0);
        dp[0] = 1;

        for (int n : nums) {
            for (int i = s; i >= n; --i) {
                dp[i] += dp[i - n];
            }
        }
        return dp[s];
    }
};
