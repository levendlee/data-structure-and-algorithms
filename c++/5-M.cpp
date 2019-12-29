class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        string str;
        auto check = [&](int i, int j) {
            while (i >= 0 && j < n && s[i] == s[j]) {
                --i;
                ++j;
            }
            int size = j - i - 1;
            if (size > str.size()) {
                str = s.substr(i + 1, size);
            }
        };
        
        for (int i = 0; i < n; ++i) {
            check(i - 1, i + 1);
            check(i, i + 1);
        }
        return str;
    }
};
