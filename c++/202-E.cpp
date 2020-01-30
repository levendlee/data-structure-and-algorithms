class Solution {
public:
    int getDigitsSqSum(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            sum += d * d;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> mem;
        while (!mem.count(n)) {
            mem.insert(n);
            if (n == 1) return true;
            n = getDigitsSqSum(n);
        }
        return false;
    }
};