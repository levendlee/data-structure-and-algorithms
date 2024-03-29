// 28 Implement strStr()
// https://leetcode.com/problems/implement-strstr

// version: 1; create time: 2020-02-01 23:38:57;
class Solution {
public:
    void calcLPSArray(const string& needle, vector<int>& lps) {
        const int n = lps.size();
        int i = 1;
        int len = 0;
        while (i < n) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        const int m = haystack.size();
        const int n = needle.size();

        vector<int> lps(n, 0);
        calcLPSArray(needle, lps);

        int i = 0, j = 0;
        while (i < m) {
            if (haystack[i] == needle[j]) {
                ++i; ++j;
                if (j == n) return i - n;
            } else {
                if (j != 0)
                    j = lps[j-1];
                else
                    ++i;
            }
        }

        return -1;
    }
};

// 2023/11/04

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int n = haystack.size();
        const int k = needle.size();

        for (int i = 0; i <= n - k; ++i) {
            if (std::equal(needle.begin(), needle.end(), haystack.begin() + i)) {
                return i;
            }
        }

        return -1;
    }
};

