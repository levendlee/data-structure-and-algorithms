// 9 Palindrome Number
// https://leetcode.com/problems/palindrome-number

// version: 1; create time: 2020-02-01 22:21:27;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        /*
        auto s = std::to_string(x);
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i; --j;
        }
        */
        if (x < 10) return true;

        long base = 10;
        while (base * 10 <= x) base *= 10;

        while (base >= 1) {
            if (x / base != x % 10) return false;
            x = (x % base) / 10;
            base = base / 100;
        }

        return true;
    }
};
