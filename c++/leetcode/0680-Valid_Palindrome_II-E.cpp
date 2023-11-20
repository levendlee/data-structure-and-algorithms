// 680 Valid Palindrome II
// https://leetcode.com/problems/valid-palindrome-ii

// version: 1; create time: 2020-01-15 00:16:21;
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

//

class Solution {
public:
    bool validPalindrome(string s) {
        const int n = s.size();

        function<bool(bool)> helper;
        helper = [&](bool delete_left) {
            bool deleted = false;
            int i = 0, j = n - 1;
            while (i < j) {
                if (s[i] != s[j]) {
                    if (deleted) return false;
                    if (delete_left) {
                        ++i;
                    } else {
                        --j;
                    }
                    deleted = true;
                } else {
                    ++i;
                    --j;
                }
            }
            return true;
        };

        return helper(true) || helper(false);
    }
};
