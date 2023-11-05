// 392 Is Subsequence
// https://leetcode.com/problems/is-subsequence

// version: 1; create time: 2020-01-26 21:23:30;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int m = s.size();
        const int n = t.size();
        if (m > n) return false;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                ++i; ++j;
            } else {
                ++j;
            }
        }
        return i == m;
    }
};


// 2023/11/04
class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int m = s.size(), n = t.size();

        int i = 0, j = 0;
        while (i < m && j < n) {
            while (j < n && s[i] != t[j]) ++j;
            if (j < n && s[i] == t[j]) {
                ++i;
                ++j;
            }
        }

        return i == m;
    }
};
