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