// 209 Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum

// version: 1; create time: 2020-01-26 21:40:28;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int n = nums.size();
        int min_dist = n + 1;
        int sum = 0;
        int i = 0, j = 0;
        while (j < n) {
            sum += nums[j];
            while (i <= j && sum >= s) {
                min_dist = std::min(min_dist, j - i + 1);
                sum -= nums[i++];
            }
            ++j;
        }
        return min_dist > n ? 0 : min_dist;
    }
};

// 2023/09/28

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();

        // O(Nlog(N))
        /*
        vector<int> sums(n + 1);
        sums[0] = 0;
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        if (sums[n] < target) {
            return 0;
        }

        int res = n;
        for (int i = 0; i < n; ++i) {
            auto iter = std::lower_bound(sums.begin() + i, sums.end(), sums[i] + target);
            if (iter == sums.end()) continue;
            int dist = std::distance(sums.begin() + i, iter);
            res = std::min(res, dist) ;
        }

        return res;
        */

        int res = INT_MAX;
        int i = 0, j = 0, sum = 0;
        while (j < n) {
            sum += nums[j];
            while ((sum >= target) && (i <= j)) {
                res = std::min(res, j - i + 1);
                sum -= nums[i++];
            }
            ++j;
        }
        return res == INT_MAX ? 0 : res;
    }
};
