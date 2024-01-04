class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int stk = 0;
        int n = s.size(), i = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++stk;
            } else if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    score += 1 << (stk - 1);
                }
                --stk;
            }
        }
        return score;
    }
};
