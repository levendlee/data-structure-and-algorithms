class Solution {
public:
    int calcSteps(long n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += std::min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        if (k == 1) return 1;
        long num = 1; --k;
        while (k) {
            auto steps = calcSteps(n, num, num + 1);
            if (steps < k) {
                k -= steps;
                ++num;
            } else if (steps == k) {
                return num + 1;
            } else {
                --k;
                num *= 10;
            }
        }
        return num;
    }
};