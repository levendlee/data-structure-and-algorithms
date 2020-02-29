// 22 Generate Parentheses
// https://leetcode.com/problems/generate-parentheses

// version: 1; create time: 2020-01-19 21:53:43;
class Solution {
public:
    void dfs(string& cur, const int lcnt, const int rcnt, const int limit, vector<string>& res) {
        if (cur.size() == 2 * limit) {
            res.push_back(cur);
            return;
        }
        if (lcnt < limit) {
            cur.push_back('(');
            dfs(cur, lcnt + 1, rcnt, limit, res);
            cur.pop_back();
        }
        if (lcnt > rcnt && rcnt < limit) {
            cur.push_back(')');
            dfs(cur, lcnt, rcnt + 1, limit, res);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {};
        if (n == 1) return {"()"};

        vector<string> res;
        string cur;
        dfs(cur, 0, 0, n, res);
        return res;
    }
};
