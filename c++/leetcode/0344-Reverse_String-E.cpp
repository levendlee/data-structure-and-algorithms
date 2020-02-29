// 344 Reverse String
// https://leetcode.com/problems/reverse-string

// version: 1; create time: 2020-02-01 23:52:48;
class Solution {
public:
    void reverseString(vector<char>& s) {
        const int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            std::swap(s[i++], s[j--]);
        }
    }
};
