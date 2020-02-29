// 772 Basic Calculator III
// https://leetcode.com/problems/basic-calculator-iii

// version: 1; create time: 2019-12-24 11:07:44;
class Solution {
public:
    long getNumber(const string& expr, int& idx) {
        const int n = expr.size();
        const int s = idx;
        while (idx < n && isdigit(expr[idx])) ++idx;
        return std::stol(expr.substr(s, idx - s));
    }

    int basicOperation(long lhs, long rhs, char op) {
        switch (op) {
            case '+': return lhs + rhs;
            case '-': return lhs - rhs;
            case '*': return lhs * rhs;
            case '/': return lhs / rhs;
        }
        return 0;
    }

    void evaluateTop(std::stack<long>& nums, std::stack<char>& ops) {
        const auto rhs = nums.top(); nums.pop();
        const auto lhs = nums.top(); nums.pop();
        const auto res = basicOperation(lhs, rhs, ops.top());
        ops.pop();
        nums.push(res);
    }

    bool isPrecedence(char op0, char op1) {
        return (op0 != '(') &&
               !((op0 == '+' || op0 == '-') && (op1 == '*' || op1 == '/'));
    }

    int calculate(const string& expr) {
        std::stack<long> nums;   // numbers
        std::stack<char> ops;    // operators

        const int n = expr.size();
        int idx = 0;
        int is_op = false;
        while (idx < n) {
            if (isdigit(expr[idx])) {
                const auto num = getNumber(expr, idx);
                nums.push(num);
                is_op = true;
                continue;
            }

            if (expr[idx] == '(') {
                ops.push('(');
                is_op = false;
            } else if (expr[idx] == ')') {
                while (ops.top() != '(') {
                    evaluateTop(nums, ops);
                }
                ops.pop();
                is_op = true;
            } else if (expr[idx] != ' ') {
                if (!is_op) {
                    nums.push(0);
                }
                while (!ops.empty() && isPrecedence(ops.top(), expr[idx])) {
                    evaluateTop(nums, ops);
                }
                ops.push(expr[idx]);
                is_op = false;
            }
            ++idx;
        }

        while (!ops.empty()) {
            evaluateTop(nums, ops);
        }

        return nums.top();
    }
};


// version: 2; create time: 2020-02-20 23:00:41;
class Solution {
public:
    int calculate(string s) {
        stack<long> nums;
        stack<char> ops;
        const int n = s.size();
        int i = 0;
        int pre_num = false;

        auto calc = [&]() {
            auto rhs = nums.top(); nums.pop();
            auto lhs = nums.top(); nums.pop();
            auto op = ops.top(); ops.pop();
            auto res = op == '+' ? lhs + rhs :
                       op == '-' ? lhs - rhs :
                       op == '*' ? lhs * rhs :
                       (lhs / rhs);
            nums.push(res);
        };

        while (i < n) {
            if (s[i] != ' ') {
                if (isdigit(s[i])) {
                    auto j = i;
                    while (j < n && isdigit(s[j])) j++;
                    auto num = stol(s.substr(i, j - i));
                    pre_num = true;
                    nums.push(num);
                    i = j - 1;
                } else if (s[i] == ')') {
                    while (ops.top() != '(') {
                        calc();
                    }
                    pre_num = true;
                    ops.pop();
                } else if (s[i] == '(') {
                    pre_num = false;
                    ops.push(s[i]);
                } else {
                    if (s[i] == '-' && !pre_num) nums.push(0);
                    while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                        calc();
                    }
                    if (s[i] == '+' || s[i] == '-') {
                        while (!ops.empty() && (ops.top() == '+' || ops.top() == '-')) {
                            calc();
                        }
                    }
                    pre_num = false;
                    ops.push(s[i]);
                }
            }
            ++i;
        }

        while (!ops.empty()) {
            calc();
        }

        return nums.top();
    }
};
