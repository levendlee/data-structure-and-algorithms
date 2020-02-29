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
