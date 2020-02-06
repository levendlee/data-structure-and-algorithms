class Solution {
public:
    bool isPalindrome(string s) {
        const int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !isalpha(s[i]) && !isdigit(s[i])) ++i;
            while (i < j && !isalpha(s[j]) && !isdigit(s[j])) --j;
            if (s[i] != s[j] && tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i; --j;
        }
        return true;
    }
};