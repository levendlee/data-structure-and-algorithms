// 45 Jump Game II
// https://leetcode.com/problems/jump-game-ii

// version: 1; create time: 2020-01-06 23:37:44;
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;

        int step = 0;
        int cur = 0, bound = 0;
        while (bound < n-1 ) {
            int new_bound = bound;
            for (int i = cur; i <= bound; ++i) {
                new_bound = std::max(new_bound, i + nums[i]);
            }
            cur = bound + 1;
            bound = new_bound;
            ++step;
        }
        return step;
    }
};

// 2023/09/10

class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        vector<int> min_jumps(n, INT_MAX);
        min_jumps[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (min_jumps[i] == INT_MAX) continue;
            for (int j = 1; j <= nums[i] && i + j < n; ++j) {
                min_jumps[i + j] = std::min(min_jumps[i + j], min_jumps[i] + 1);
            }
        }
        return min_jumps[n - 1];
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 1; i < n; ++i) {
            nums[i] = std::max(nums[i] + i, nums[i - 1]);
        }
        int jumps = 0;
        int idx = 0;
        while (idx < n - 1) {
            ++jumps;
            idx = nums[idx];
        }
        return jumps;
    }
};
