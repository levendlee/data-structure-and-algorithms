// 213 House Robber II
// https://leetcode.com/problems/house-robber-ii

// version: 1; create time: 2020-01-26 22:35:02;
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0];

        int hpre2 = 0, hpre1 = 0;
        int pre2 = 0, pre1 = 0;
        for (int i = 0; i < n; ++i) {
            int hcur = std::max(hpre1, hpre2 + nums[i]);
            hpre2 = hpre1; hpre1 = hcur;
            if (i == 0) continue;
            int cur = std::max(pre1, pre2 + nums[i]);
            pre2 = pre1; pre1 = cur;
        }
        return std::max(pre1, hpre2);
    }
};

//

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        int max_gain = 0;

        // (i - 2, i - 1) x (not rob, rob)
        int dp[4] = {0};

        auto update = [&](int gain) {
            int ndp[2] = {0};
            // Don't rob this house.
            ndp[0] = *max_element(dp, dp + 4);
            // Rob this house.
            ndp[1] = *max_element(dp, dp + 3) + gain;
            dp[0] = dp[2];
            dp[1] = dp[3];
            dp[2] = ndp[0];
            dp[3] = ndp[1];
        };

        // Don't rob last one.
        for (int i = 0; i < n - 1; ++i) {
            update(nums[i]);
        }
        max_gain = max(max_gain, *max_element(dp, dp + 4));

        // Rob last one.
        fill(dp, dp + 4, 0);
        for (int i = 1; i < n; ++i) {
            update(nums[i]);
        }
        max_gain = max(max_gain, *max_element(dp, dp + 4));

        if (n == 1) {
            return nums[0];
        }
        return max_gain;
    }
};

//

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        int max_gain = 0;

        int t1 = 0, t2 = 0;

        auto update = [&](int gain) {
            int t = max(t2 + gain, t1);
            t2 = t1;
            t1 = t;
        };

        // Don't rob last one.
        for (int i = 0; i < n - 1; ++i) {
            update(nums[i]);
        }
        max_gain = max({max_gain, t1, t2});

        // Rob last one.
        t1 = 0; t2 = 0;
        for (int i = 1; i < n; ++i) {
            update(nums[i]);
        }
        max_gain = max({max_gain, t1, t2});

        if (n == 1) {
            return nums[0];
        }
        return max_gain;
    }
};