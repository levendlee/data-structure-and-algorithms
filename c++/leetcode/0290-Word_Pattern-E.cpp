class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2w;
        unordered_map<string, char> w2c;

        const int m = pattern.size();
        const int n = s.size();
        int i = 0, j = 0, p = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') ++j;
            i = j;
            while (j < n && s[j] != ' ') ++j;
            if (i != j) {
                if (p == m) return false;
                string w = s.substr(i, j - i);
                char c = pattern[p];
                if (c2w.count(c) && c2w[c] != w) return false;
                if (w2c.count(w) && w2c[w] != c) return false;
                c2w[c] = w;
                w2c[w] = c;
                ++p;
            }
        }

        return p == m;
    }
};
