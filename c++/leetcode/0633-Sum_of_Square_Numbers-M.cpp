class Solution {
public:
    bool judgeSquareSum(int c) {
        // Brute Force
        // T: O(N). S: O(1)
        /*
        for (int64_t i = 0; i * i <= c; ++i) {
            for (int64_t j = i; j * j <= c; ++j) {
                int sum = i * i + j * j;
                if (sum > c) break;
                if (sum == c) return true;
            }
        }
        */

        // Hashmap. Still TLE
        // T: O(sqrt(N)). S: O(sqrt(N))
        /*
        unordered_set<int64_t> squares;
        for (int64_t i = 0; i <= c; ++i) {
            int64_t sq = i * i;
            if (sq > c) break;
            if (sq == c) return true;
            squares.insert(i * i);
            if (squares.count(c - sq)) return true;
        }
        return false;
        */

        // Can use BST to find sqrt.
        int sqrt_c = 0;
        int lo = 0, hi = c;
        while (lo < hi) {
            int64_t mid = (lo + hi) / 2; // Uses lo in case of tie
            int64_t mid2 = mid * mid;
            if (mid2 > c) {
                hi = mid;
            } else if (mid2 < c) {
                lo = mid + 1;
            } else {
                return true;
            }
        }
        sqrt_c = lo;

        for (int64_t a = 0; 2 * a * a <= c; ++a) {
            int b2 = c - a * a;
            int lo = 0, hi = sqrt_c;
            while (lo <= hi) {
                int64_t mid = (lo + hi) / 2; // Uses lo in case of tie
                int64_t mid2 = mid * mid;
                if (mid2 > b2) {
                    hi = mid - 1;
                } else if (mid2 < b2) {
                    lo = mid + 1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};