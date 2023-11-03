// 5 Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring

// version: 1; create time: 2019-12-30 11:34:15;
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

// 2023/11/02

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        std::string longest = s.substr(0, 1);
        for (int d = 2; d <= n; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                int j = i + d - 1;
                dp[i][j] = (d == 2 || dp[i + 1][j - 1]) && (s[i] == s[j]);
                if (dp[i][j]) longest = s.substr(i, d);
            }
        }

        return longest;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        
        std::string longest = "";
        auto find_palindrome = [&](int i, int j) {
            while (i >= 0 && j < n && s[i] == s[j]) {
                --i;
                ++j;
            }
            int d = j - i - 1;
            if (d > longest.size()) {
                longest = s.substr(i + 1, d);
            }
        };

        for (int i = 0; i < n; ++i) {
            find_palindrome(i, i + 1);
            find_palindrome(i - 1, i + 1);
        }

        return longest;
    }
};
