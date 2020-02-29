// 248 Strobogrammatic Number III
// https://leetcode.com/problems/strobogrammatic-number-iii

// version: 1; create time: 2019-12-14 11:30:21;
class Solution {
public:
    bool isValidNumber(const string& a) {
        if (a.size() == 1) {
            return true;
        }
        return a[0] != '0';
    }

    int compareStringNumber(const string& a, const string& b) {
        // if a <= b, return 1;
        // if a > b, return 0;
        const int na = a.size();
        const int nb = b.size();
        if (na < nb) {
            return 1;
        }
        if (na > nb) {
            return 0;
        }
        return a <= b;
    }

    int countStrobInRange(string num, const string& lo, const string& hi) {
        constexpr char pairs[5][2] = {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        int cnt = 0;
        if (compareStringNumber(num, hi)) {
            if (compareStringNumber(lo, num)) {
                cnt += isValidNumber(num);
            }
            if (num.size() + 2 <= hi.size()) {
                for (int i = 0; i < 5; ++i) {
                    cnt += countStrobInRange(pairs[i][0] + num + pairs[i][1], lo, hi);
                }
            }
        } else {
            // no need to expand the number
        }
        return cnt;
    }
    int strobogrammaticInRange(string low, string high) {
        // 0, 1, 8
        // 6, 9
        const string starts[] = {"", "0", "1", "8"};
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
            cnt += countStrobInRange(starts[i], low, high);
        return cnt;
    }
};
