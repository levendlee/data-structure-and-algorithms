// 374 Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower

// version: 1; create time: 2020-02-01 15:12:22;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            } else if (res == -1) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

//

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 0, hi = n;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            int status = guess(mid);
            if (status == 0) {
                return mid;
            } else if (status == -1) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
