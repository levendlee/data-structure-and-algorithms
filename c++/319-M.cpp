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