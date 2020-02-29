// 319 Bulb Switcher
// https://leetcode.com/problems/bulb-switcher

// version: 1; create time: 2020-02-08 15:20:38;
class Solution {
public:
    int bulbSwitch(int n) {
        /*
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int switches = 0;
            for (int k = 1; k <= i; ++k) {
                switches += i % k == 0;
            }
            cnt += switches % 2;
        }
        return cnt;
        */
        return sqrt(n);
    }
};
