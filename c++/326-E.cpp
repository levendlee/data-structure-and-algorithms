class Solution {
public:
    bool isPowerOfThree(int n) {
        constexpr int max_pow = pow(3, 19);
        return (n > 0) && (max_pow % n == 0);
    }
};