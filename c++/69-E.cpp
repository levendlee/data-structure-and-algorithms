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