// 301 Remove Invalid Parentheses
// https://leetcode.com/problems/remove-invalid-parentheses

// version: 1; create time: 2020-01-15 00:01:49;
class Solution {
public:
    void removeHelper(const string& s, const int start, const char l_op, const char r_op, unordered_set<string>& results) {
        const int n = s.size();
        int stack = 0;
        int idx = start;
        while (idx < n) {
            if (s[idx] == l_op) stack++;
            else if (s[idx] == r_op) stack--;
            if (stack < 0) break;
            ++idx;
        }
        if (idx == n) {
            auto tmp = s;
            std::reverse(tmp.begin(), tmp.end());
            if (l_op == ')') {
                results.insert(tmp);
            } else {
                removeHelper(tmp, 0, ')', '(', results);
            }
        } else {
            for (int i = 0; i <= idx; ++i) {
                if (s[i] == r_op && (i == 0 || s[i-1] != r_op)) {
                    auto tmp = s;
                    tmp.erase(i, 1);
                    removeHelper(tmp, idx, l_op, r_op, results);
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        removeHelper(s, 0, '(', ')', res);
        return vector<string>(res.begin(), res.end());
    }
};

//

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        const int n = s.size();

        int p = 0, removes = 0;
        for (char c : s) {
            p += c == '(';
            p -= c == ')';
            if (p < 0) {
                ++removes;
                ++p;
            }
        }
        removes += p;

        unordered_set<string> res;
        function<void(string&, int, int, int)> backtracking;
        backtracking = [&](string& cur, int i, int p, int r) {
            // cur: current working string
            // i: current working index
            // p: number of unmatched left parentheses
            // r: number of parentheses to remove
            if (p < 0 || r < 0) return;
            if (i == n) {
                if (p == 0) {
                    res.insert(cur);
                }
            } else {
                // remove
                if (s[i] == '(' || s[i] == ')') {
                    backtracking(cur, i + 1, p, r - 1);
                }
                // keep
                int p_delta = s[i] == '(' ? 1 : (s[i] == ')' ? -1 : 0);
                cur.push_back(s[i]);
                backtracking(cur, i + 1, p + p_delta, r);
                cur.pop_back();
            }
        };
        string cur;
        backtracking(cur, 0, 0, removes);

        return {res.begin(), res.end()};
    }
};

//

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        const int n = s.size();

        int p = 0, removes = 0;
        for (char c : s) {
            p += c == '(';
            p -= c == ')';
            if (p < 0) {
                ++removes;
                ++p;
            }
        }
        removes += p;

        unordered_set<string> res;
        vector<unordered_set<string>> mem(n + 1);

        function<void(string&, int, int, int)> backtracking;
        backtracking = [&](string& cur, int i, int p, int r) {
            // cur: current working string
            // i: current working index
            // p: number of unmatched left parentheses
            // r: number of parentheses to remove
            if (p < 0 || r < 0) return;

            if (mem[i].count(cur)) {
                return;
            }
            mem[i].insert(cur);

            if (i == n) {
                if (p == 0) {
                    res.insert(cur);
                }
            } else {
                // remove
                if (s[i] == '(' || s[i] == ')') {
                    backtracking(cur, i + 1, p, r - 1);
                }
                // keep
                int p_delta = s[i] == '(' ? 1 : (s[i] == ')' ? -1 : 0);
                cur.push_back(s[i]);
                backtracking(cur, i + 1, p + p_delta, r);
                cur.pop_back();
            }
        };
        string cur;
        backtracking(cur, 0, 0, removes);

        return {res.begin(), res.end()};
    }
};
