// 150 Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation

// version: 1; create time: 2020-01-30 21:05:56;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (const auto& t : tokens) {
            if (isdigit(t.back())) {
                nums.push(std::stoi(t));
                continue;
            }
            auto rhs = nums.top(); nums.pop();
            auto lhs = nums.top(); nums.pop();
            if (t[0] == '+') {
                nums.push(lhs + rhs);
            } else if (t[0] == '-') {
                nums.push(lhs - rhs);
            } else if (t[0] == '*') {
                nums.push(lhs * rhs);
            } else {
                nums.push(lhs / rhs);
            }
        }
        return nums.top();
    }
};

// 2023/10/18

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        for (const auto& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int rhs = stk.top();
                stk.pop();
                int lhs = stk.top();
                stk.pop();
                int res;
                if (t == "+") {
                    res = lhs + rhs;
                } else if (t == "-") {
                    res = lhs - rhs;
                } else if (t == "*") {
                    res = lhs * rhs;
                } else {
                    res = lhs / rhs;
                }
                stk.push(res);
            } else {
                stk.push(std::atoi(t.c_str()));
            }
        }

        return stk.top();
    }
};
