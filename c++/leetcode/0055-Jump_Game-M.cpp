// 55 Jump Game
// https://leetcode.com/problems/jump-game

// version: 1; create time: 2020-02-01 16:17:06;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int max_reach = 0;
        for (int i = 0; i < n; ++i) {
            if (max_reach < i) return false;
            max_reach = std::max(max_reach, i + nums[i]);
        }
        return true;
    }
};

// 2023/09/10
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int max_idx = nums[0];
        for (int i = 1; i < n; ++i) {
            if (max_idx < i) {
                break;
            }
            max_idx = std::max(max_idx, i + nums[i]);
        }
        return max_idx >= n - 1;
    }
};
