// 634 Find the Derangement of An Array
// https://leetcode.com/problems/find-the-derangement-of-an-array

// version: 1; create time: 2020-01-19 20:41:36;
class Solution {
public:
    int findDerangement(int n) {
        constexpr int mod = 1e9 + 7;
        if (n <= 1) return 0;
        long long pre = 0, cur = 1;
        for (int i = 3; i <= n; ++i) {
            auto nex = (i - 1) * (cur + pre);
            pre = cur;
            cur = nex % mod;
        }
        return cur;
    }
};
