class Solution {
public:
    int trailingZeroes(int n) {
        int num_zeros = 0;
        for (int i = 5; i <= n; i += 5) {
            int num = i;
            while (num % 5 == 0) {
                num = num / 5;
                ++num_zeros;
            }
        }
        return num_zeros;
    }
};
