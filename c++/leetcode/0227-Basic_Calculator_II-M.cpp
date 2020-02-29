// 227 Basic Calculator II
// https://leetcode.com/problems/basic-calculator-ii

// version: 1; create time: 2019-12-23 12:03:47;
class Solution {
public:
    int getNumber(const string& expr, int& idx) {
        const int n = expr.size();
        const int s = idx;
        while (idx < n && isdigit(expr[idx])) ++idx;
        return std::stoi(expr.substr(s, idx - s));
    }

    int calculate(const string& expr) {
        std::vector<int> vvec{0};
        char op = '+';

        const int n = expr.size();
        int idx = 0;
        while (idx < n) {
            if (isdigit(expr[idx])) {
                const auto num = getNumber(expr, idx);
                if (op == '*') {
                    vvec.back() *= num;
                } else if (op == '/') {
                    vvec.back() /= num;
                } else {
                    vvec.push_back(op == '+' ? num : -num);
                }
                continue;
            }
            if (expr[idx] != ' ') {
                op = expr[idx];
            }
            ++idx;
        }

        return std::accumulate(vvec.begin(), vvec.end(), 0);
    }
};
