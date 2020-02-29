// 224 Basic Calculator
// https://leetcode.com/problems/basic-calculator

// version: 1; create time: 2019-12-23 11:51:54;
/*
// Recursion.
class Solution {
public:
    int getSubexpression(const string& expr, const int s) {
        // Based on the condition that the expression is not ill-formed
        int stk = 0;
        int idx = s;
        do {
            if (expr[idx] == '(') ++stk;
            else if (expr[idx] == ')') --stk;
            ++idx;
        } while (stk != 0);
        return idx - 1;
    }

    int getNumber(const string& expr, int& idx) {
        const int n = expr.size();
        const int s = idx;
        while (idx < n && isdigit(expr[idx])) ++idx;
        return std::stoi(expr.substr(s, idx - s));
    }

    int evalExpression(const string& expr, const int s, const int e) {
        int sum = 0;
        int sign = 1;
        int idx = s;
        while (idx <= e) {
            if (expr[idx] == ' ') {
                ++idx;
            } else if (expr[idx] == '(') {
                const int e = getSubexpression(expr, idx);
                // Need to remove the parenthess
                const int res = evalExpression(expr, idx + 1, e - 1);
                sum += sign * res;
                idx = e + 1;
            } else if (expr[idx] == '+') {
                sign = 1;
                ++idx;
            } else if (expr[idx] == '-') {
                sign = -1;
                ++idx;
            } else {
                const int num = getNumber(expr, idx);
                sum += sign * num;
            }
        }
        return sum;
    }

    int calculate(string s) {
        return evalExpression(s, 0, s.size() - 1);
    }
};
*/

class Solution {
public:
    int getNumber(const string& expr, int& idx) {
        const int n = expr.size();
        const int s = idx;
        while (idx < n && isdigit(expr[idx])) ++idx;
        return std::stoi(expr.substr(s, idx - s));
    }

    int calculate(const string& expr) {
        const int n = expr.size();
        std::stack<int> vstack; vstack.push(0);
        std::stack<int> sstack; sstack.push(1);
        int sign = 1;
        int idx = 0;
        while (idx < n) {
            if (isdigit(expr[idx])) {
                const int num = getNumber(expr, idx);
                vstack.top() += sign * num;
                continue;
            }
            if (expr[idx] == '(') {
                sstack.push(sign);
                vstack.push(0);
                sign = 1;
            } else if (expr[idx] == ')') {
                const auto sign = sstack.top(); sstack.pop();
                const auto num = vstack.top(); vstack.pop();
                vstack.top() += sign * num;
            } else if (expr[idx] == '+') {
                sign = 1;
            } else if (expr[idx] == '-') {
                sign = -1;
            }
            ++idx;
        }
        return sstack.top() * vstack.top();
    }
};
