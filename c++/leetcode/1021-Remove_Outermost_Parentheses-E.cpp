// 1021 Remove Outermost Parentheses
// https://leetcode.com/problems/remove-outermost-parentheses

// version: 1; create time: 2020-02-01 14:25:13;
class Solution {
public:
    string removeOuterParentheses(string S) {
        const int n = S.size();
        int i = 0, j = 0, stk = 0;
        string res;
        while (j < n) {
            if (S[j] == '(') ++stk;
            else if (S[j] == ')') -- stk;
            if (stk == 0) {
                res += S.substr(i + 1, j - i - 1);
                i = j + 1;
            }
            ++j;
        }
        return res;
    }
};
