class Solution {
public:
    double myPow(double x, long n) {
        bool neg = n < 0;
        if (x == 1) return 1;
        if (n == 0) return 1;
        n = abs(long(n));
        double res = 1;
        double cur = x;
        while (n) {
            if (n & 0x1) {
                res *= cur;
            }
            cur *= cur;
            n >>= 1;
        }
        return neg ? 1.0 / res : res;
    }
};