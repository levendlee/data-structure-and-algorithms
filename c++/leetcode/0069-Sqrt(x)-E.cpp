// 69 Sqrt(x)
// https://leetcode.com/problems/sqrtx

// version: 1; create time: 2020-02-09 23:33:39;
class Solution {
public:
    int mySqrt(int x) {
        int lo = 1, hi = x;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (mid * mid <= x) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};

// 2023/10/29

class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0, hi = x;
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            if (mid * mid > x) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        return lo;
    }
};
