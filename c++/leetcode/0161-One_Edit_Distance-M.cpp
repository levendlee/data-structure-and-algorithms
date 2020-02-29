// 161 One Edit Distance
// https://leetcode.com/problems/one-edit-distance

// version: 1; create time: 2020-02-06 00:26:37;
class Solution {
public:

    bool isOneEditDistance(string s, string t) {
        const int n1 = s.size();
        const int n2 = t.size();

        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (s[i] == t[j]) {
                ++i; ++j;
            } else {
                return (s.substr(i + 1) == t.substr(j)) || \
                       (s.substr(i) == t.substr(j + 1)) || \
                       (s.substr(i + 1) == t.substr(j + 1));
            }
        }

        return (n1 - i) + (n2 - j) == 1;
    }
};
