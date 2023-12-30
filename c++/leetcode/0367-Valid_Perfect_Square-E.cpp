// 367 Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square

// version: 1; create time: 2020-02-09 23:22:23;
class Solution {
public:
    bool isPerfectSquare(int num) {
        long i = 1;
        while (true) {
            auto sq = i * i;
            if (sq == num) return true;
            if (sq > num) return false;
            ++i;
        }
        return false;
    }
};

//

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int64_t i = 1; i <= num; ++i) {
            if (i * i == num) return true;
            if (i * i > num) return false;
        }
        return false;
    }
};
