// 647 Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings

// version: 1; create time: 2020-02-01 19:05:41;
class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        if (n == 0) return 0;

        int cnt = n;
        vector<int> even(n, true);
        vector<int> odd(n, true);
        for (int size = 2; size <= n; ++size) {
            for (int i = 0; i + size <= n; ++i) {
                int j = i + size - 1;
                bool is_palindrome = (s[i] == s[j]) && (size & 0x1 ? odd[i+1] : even[i+1]);
                cnt += is_palindrome;
                if (size & 0x1) {
                    odd[i] = is_palindrome;
                } else {
                    even[i] = is_palindrome;
                }
            }
        }
        return cnt;
    }
};

//
class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        vector<vector<bool>> is_palindromic(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            is_palindromic[i][i] = true;
        }
        int num_palindromic_substrs = n;
        for (int d = 2; d <= n; ++d) {
            for (int i = 0; i + d <= n; ++i) {
                int j = i + d - 1;
                is_palindromic[i][j] = (s[i] == s[j]) && (d == 2 || is_palindromic[i+1][j-1]);
                num_palindromic_substrs += is_palindromic[i][j];
            }
        }
        return num_palindromic_substrs;
    }
};

//
class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        int num_palindromic_substrs = 0;
        for (int c = 0; c < n; ++c) {
            ++num_palindromic_substrs;
            // Odd number. As center.
            for (int i = c - 1, j = c + 1; i >= 0 && j < n && s[i] == s[j]; --i, ++j) {
                ++num_palindromic_substrs;
            }
            // Even number. As last one of previous half.
            for (int i = c, j = c + 1; i >= 0 && j < n && s[i] == s[j]; --i, ++j) {
                ++num_palindromic_substrs;
            }
        }
        return num_palindromic_substrs;
    }
};
