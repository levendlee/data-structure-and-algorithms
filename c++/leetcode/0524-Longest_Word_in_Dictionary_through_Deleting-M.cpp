// 524 Longest Word in Dictionary through Deleting
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

// version: 1; create time: 2019-10-30 23:51:07;
class Solution {
public:
    bool match(const string& s0, const string& s1) {
        const int n0 = s0.size();
        const int n1 = s1.size();
        int i = 0, j = 0;
        while (i < n0 && j < n1) {
            if (s0[i] == s1[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        return j == n1;
    }

    string findLongestWord(string s, vector<string>& d) {
        int l = -1;
        const int n = d.size();
        for (int i = 0; i < n; ++i) {
            if (match(s, d[i])) {
                if (l == -1 || d[i].size() > d[l].size()) {
                    l = i;
                } else if ((d[i].size() == d[l].size()) && (d[i] < d[l])) {
                    l = i;
                }
            }
        }
        return l == -1 ? "" : d[l];
    }
};
