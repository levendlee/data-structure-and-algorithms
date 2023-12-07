// 246 Strobogrammatic Number
// https://leetcode.com/problems/strobogrammatic-number

// version: 1; create time: 2020-01-30 21:10:28;
class Solution {
public:
    bool rotateMatch(const char l, const char r) {
        return (l == r) && (l == '0' || l == '1' || l == '8') || (l == '6' && r == '9') || (l == '9' && r == '6');
    }

    bool isStrobogrammatic(string num) {
        const int n = num.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (!rotateMatch(num[i++], num[j--])) return false;
        }
        if ((i == j) && !rotateMatch(num[i], num[i])) return false;
        return true;
    }
};

//

class Solution {
public:
    bool isStrobogrammatic(string num) {
        const int n = num.size();
        int i = 0, j = n - 1;
        while (i < n) {
            char d0 = num[i], d1 = num[j];
            if (d0 == d1 && (d0 == '0' || d0 == '1' || d0 == '8') ||
                d0 == '6' && d1 == '9' ||
                d0 == '9' && d1 == '6') {
                ++i;
                --j;
                continue;
            };
            return false;
        }
        return true;
    }
};
