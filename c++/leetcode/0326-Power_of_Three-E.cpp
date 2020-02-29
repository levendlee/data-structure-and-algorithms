// 326 Power of Three
// https://leetcode.com/problems/power-of-three

// version: 1; create time: 2020-02-01 18:54:08;
class Solution {
public:
    bool isPowerOfThree(int n) {
        constexpr int max_pow = pow(3, 19);
        return (n > 0) && (max_pow % n == 0);
    }
};
