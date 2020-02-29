// 70 Climbing Stairs
// https://leetcode.com/problems/climbing-stairs

// version: 1; create time: 2020-02-01 23:55:16;
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int cur = 1, pre = 1;
        for (int i = 2; i <= n; ++i) {
            int nex = cur + pre;
            pre = cur;
            cur = nex;
        }
        return cur;
    }
};
