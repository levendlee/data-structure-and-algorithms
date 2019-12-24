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