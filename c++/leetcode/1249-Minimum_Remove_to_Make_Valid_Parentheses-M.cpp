// 1249 Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

// version: 1; create time: 2020-01-15 18:45:14;
class Solution {
public:
    void removeHelper(string& s, const int start, const char l_op, const char r_op) {
        int stack = 0;
        int idx = start;
        const int n = s.size();
        while (idx < n) {
            if (s[idx] == l_op) ++stack;
            else if (s[idx] == r_op) --stack;
            if (stack < 0) break;
            ++idx;
        }
        if (idx == n) {
            std::reverse(s.begin(), s.end());
            if (l_op == ')') {
                return;
            } else {
                removeHelper(s, 0, ')', '(');
            }
        } else {
            s.erase(idx, 1);
            removeHelper(s, idx, l_op, r_op);
        }
    }

    string minRemoveToMakeValid(string s) {
        removeHelper(s, 0, '(', ')');
        return s;
    }
};
