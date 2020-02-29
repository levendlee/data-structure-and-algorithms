// 921 Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

// version: 1; create time: 2020-02-07 21:44:06;
class Solution {
public:
    int minAddToMakeValid(string S) {
        int cnt = 0;
        int stk = 0;
        for (const auto& c : S) {
            if (c == '(') ++stk;
            else if (c == ')') --stk;
            if (stk < 0) { ++cnt; stk = 0; }
        }
        if (stk > 0) cnt += stk;
        return cnt;
    }
};
