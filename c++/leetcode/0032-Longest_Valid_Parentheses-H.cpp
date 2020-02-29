// 32 Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses

// version: 1; create time: 2020-01-19 21:24:44;
class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        int i = 0, j = 0, stack = 0, longest = 0;
        while (j < n) {
            stack += s[j] == '(' ? 1 : -1;
            while (stack < 0) {
                stack -= s[i++] == '(' ? 1 : -1;
            }
            if (stack == 0) {
                longest = std::max(longest, j - i + 1);
            }
            ++j;
        }

        i = n - 1, j = n - 1, stack = 0;
        while (j >= 0) {
            stack += s[j] == ')' ? 1 : -1;
            while (stack < 0) {
                stack -= s[i--] == ')' ? 1 : -1;
            }
            if (stack == 0) {
                longest = std::max(longest, i - j + 1);
            }
            --j;
        }
        return longest;
    }
};
