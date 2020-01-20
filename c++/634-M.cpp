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