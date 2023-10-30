// 50 Pow(x, n)
// https://leetcode.com/problems/powx-n

// version: 1; create time: 2020-01-30 23:20:58;
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

// 2023/10/23

class Solution {
public:
    double myPow(double x, int n) {
        bool inv = n < 0;

        n = abs(n);
        double pow = 1.0;
        double pow2 = x;
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 0x1) {
                pow *= pow2;
            }
            pow2 *= pow2;
        }

        return inv ? 1.0 / pow : pow;
    }
};
