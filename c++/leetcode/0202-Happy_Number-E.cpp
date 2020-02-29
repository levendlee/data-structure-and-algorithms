// 202 Happy Number
// https://leetcode.com/problems/happy-number

// version: 1; create time: 2020-01-29 23:31:39;
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
