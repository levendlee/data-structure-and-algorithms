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

// 2023/10/23

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;

        function<void(string&, int)> backtracing;
        backtracing = [&](string& s, int added_left) {
            if (s.size() == 2 * n) {
                results.push_back(s);
                return;
            }

            int added_right = s.size() - added_left;
            int remaining_left = n - added_left;
            int remaining_right = n - added_right;

            if (remaining_left > 0) {
                s.push_back('(');
                backtracing(s, added_left + 1);
                s.pop_back();
            }

            if (added_left > added_right) {
                s.push_back(')');
                backtracing(s, added_left);
                s.pop_back();
            }
        };

        string s;
        backtracing(s, 0);
        return results;
    }
};
