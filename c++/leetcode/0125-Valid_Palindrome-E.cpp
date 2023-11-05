// 125 Valid Palindrome
// https://leetcode.com/problems/valid-palindrome

// version: 1; create time: 2020-02-05 22:09:30;
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

// 2023/11/04

class Solution {
public:
    bool isPalindrome(string s) {
        const int n = s.size();

        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j && tolower(s[i++]) != tolower(s[j--])) return false;
        }

        return true;
    }
};
