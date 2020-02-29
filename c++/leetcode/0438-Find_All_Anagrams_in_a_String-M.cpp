// 438 Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string

// version: 1; create time: 2020-01-16 00:30:39;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = s.size();
        const int m = p.size();
        if (n < m || n == 0 || m == 0) return {};

        int counter[26] = {0};
        for (int i = 0; i < m; ++i) {
            ++counter[p[i] - 'a'];
        }

        vector<int> res;
        int window[26] = {0};
        int match = 0;
        for (int i = 0; i < n; ++i) {
            const char c = s[i] - 'a';
            if (++window[c] <= counter[c]) ++match;
            if (match == m) {
                res.push_back(i + 1 - m);
            }
            if (i >= m - 1) {
                const char c = s[i + 1 - m] - 'a';
                auto cnt = --window[c];
                if (cnt >= 0 && cnt < counter[c]) --match;
            }
        }
        return res;
    }
};
