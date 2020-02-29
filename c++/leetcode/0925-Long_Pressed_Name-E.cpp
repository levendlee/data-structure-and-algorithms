// 925 Long Pressed Name
// https://leetcode.com/problems/long-pressed-name

// version: 1; create time: 2020-01-26 20:47:18;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        const int m = name.size();
        const int n = typed.size();
        if (m > n) return false;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && j < n && name[i] == typed[j]) {
                ++i; ++j;
            } else if (j > 0 && typed[j] == typed[j-1]) {
                ++j;
            } else {
                return false;
            }
        }
        return i == m;
    }
};
