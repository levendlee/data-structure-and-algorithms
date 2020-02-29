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
