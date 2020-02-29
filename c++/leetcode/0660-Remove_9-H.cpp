// 660 Remove 9
// https://leetcode.com/problems/remove-9

// version: 1; create time: 2020-02-02 22:06:09;
class Solution {
public:
    int newInteger(int n) {
        string res;
        while (n) {
            char c = '0' + n % 9;
            res = c + res;
            n /= 9;
        }
        return stoi(res);
    }
};
