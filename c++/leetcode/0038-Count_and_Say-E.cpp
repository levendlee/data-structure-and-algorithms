// 38 Count and Say
// https://leetcode.com/problems/count-and-say

// version: 1; create time: 2020-02-01 20:50:22;
class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        if (n == 1) return cur;
        for (int i = 2; i <= n; ++i) {
            string nex;
            const int m = cur.size();
            int j = 0;
            while (j < m) {
                int s = j;
                while (j + 1 < m && cur[j] == cur[j+1]) ++j;
                nex += std::to_string(j - s + 1) + cur[j];
                ++j;
            }
            cur = std::move(nex);
        }
        return cur;
    }
};

//

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string ns;
            int k = 0;
            while (k < s.size()) {
                int start = k;
                while (k + 1 < s.size() && s[k] == s[k + 1]) ++k;
                int repeats = k - start + 1;
                ns += to_string(repeats) + s[k];
                ++k;
            }
            s = move(ns);
        }
        return s;
    }
};
