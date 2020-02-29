// 10 Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching

// version: 1; create time: 2020-02-02 21:02:31;
class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();

        vector<bool> cur(n + 1, false);
        cur[0] = true;
        for (int i = 1; i < n; i += 2) {
            if (p[i] == '*') cur[i+1] = true;
            else break;
        }

        vector<bool> nex(n + 1, false);

        for (int i = 0; i < m; ++i) {
            nex[0] = false;
            for (int j = 0; j < n; ++j) {
                if (p[j] == s[i] || p[j] == '.') {
                    nex[j+1] = cur[j];
                } else if (p[j] == '*') {
                    nex[j+1] = nex[j-1] || (p[j-1] == s[i] || p[j-1] == '.') && cur[j+1];
                } else {
                    nex[j+1] = false;
                }
            }
            std::swap(cur, nex);
        }

        return cur[n];
    }
};
