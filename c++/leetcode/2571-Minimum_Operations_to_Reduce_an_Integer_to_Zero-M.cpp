class Solution {
public:
    int minOperations(int num) {
        int ops = 0;
        while (num > 0) {
            if ((num & 3) == 3) {
                num += 1;
                ops += 1;
            } else if (num & 1) {
                num -= 1;
                ops += 1;
            } else {
                num >>= 1;
            }
        }
        return ops;
    }
};