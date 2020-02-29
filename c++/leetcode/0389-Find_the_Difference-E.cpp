// 389 Find the Difference
// https://leetcode.com/problems/find-the-difference

// version: 1; create time: 2020-02-01 14:27:39;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int counter[26] = {0};
        for (auto c : s) {
            ++counter[c - 'a'];
        }
        for (auto c : t) {
            if (--counter[c - 'a'] < 0) {
                return c;
            }
        }
        return ' ';
    }
};
