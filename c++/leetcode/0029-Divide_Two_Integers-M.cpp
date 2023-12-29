// 29 Divide Two Integers
// https://leetcode.com/problems/divide-two-integers

// version: 1; create time: 2020-02-06 00:19:59;
class Solution {
public:
    int divide(long dividend, long divisor) {
        int sign = dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0 ? 1 : -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long lo = 0, hi = dividend;
        while (lo < hi) {
            long mid = lo + (hi - lo + 1) / 2;
            if (divisor * mid > dividend) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        auto res = lo * sign;
        return res > INT_MAX ? INT_MAX : res;
    }
};

//

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = (dividend > 0) ^ (divisor > 0);
        auto abs_dividend = abs(static_cast<int64_t>(dividend));
        auto abs_divisor = abs(static_cast<int64_t>(divisor));
        int64_t qutotient_base = 1;
        int64_t qutotient = 0;
        while ((abs_divisor << 1) <= abs_dividend) {
            abs_divisor <<= 1;
            qutotient_base <<= 1;
        }
        while (abs_dividend && abs_divisor > 0) {
            if (abs_dividend >= abs_divisor) {
                abs_dividend -= abs_divisor;
                qutotient += qutotient_base;
            }
            abs_divisor >>= 1;
            qutotient_base >>= 1;
        }
        return negative ? std::max(-qutotient, static_cast<int64_t>(INT_MIN)):
                          std::min(qutotient, static_cast<int64_t>(INT_MAX));
    }
};
