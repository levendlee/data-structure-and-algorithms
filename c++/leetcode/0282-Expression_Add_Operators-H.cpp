class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> results;

        const int n = num.size();
        function<void(int, long long, long long, const string&)> dfs;
        dfs = [&](int i, long long sum, long long lhs, const string& expr) {
            if (i == n) {
                if (sum + lhs == target) {
                    results.push_back(expr);
                }
                return;
            }

            // Find next number.
            for (int j = i; j < n; ++j) {
                // No leading zeros.
                if (num[i] == '0' && j != i) break;

                string s = num.substr(i, j - i + 1);
                long long rhs = stoll(s);
                if (expr.empty()) {
                    dfs(j + 1, 0, rhs, s);
                } else {
                    // Insert "+"
                    dfs(j + 1, sum + lhs, rhs, expr + "+" + s);
                    // Insert "-"
                    dfs(j + 1, sum + lhs, -rhs, expr + "-" + s);
                    // Insert "*"
                    dfs(j + 1, sum, lhs * rhs, expr + "*" + s);
                }
            }
        };
        dfs(0, 0, 0, "");

        return results;
    }
};
