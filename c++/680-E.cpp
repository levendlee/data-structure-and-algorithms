class Solution {
public:
    bool helper(string& s, bool deleted, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else if (!deleted && s[i] == s[j-1] && helper(s, true, i, j - 1)) {
                return true;
            } else if (!deleted && s[i+1] == s[j] && helper(s, true, i + 1, j)) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        const int n = s.size();
        if (n <= 1) return true;
        return helper(s, false, 0, n - 1);
    }
};