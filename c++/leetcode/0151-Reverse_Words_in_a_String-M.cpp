class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        const int n = s.size();
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') {
                ++j;
            }
            i = j;
            while (j < n && s[j] != ' ') {
                ++j;
            }
            reverse(s.begin() + i, s.begin() + j);
        }

        i = 0, j = 0;
        while (j < n) {
            if (s[j] != ' ' || i > 0 && s[i - 1] != ' ') {
                s[i] = s[j];
                ++i;
            }
            ++j;
        }
        if (s.back() == ' ') {
            --i;
        }
        return s.substr(0, i);
    }
};
