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