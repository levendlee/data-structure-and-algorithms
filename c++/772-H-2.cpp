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