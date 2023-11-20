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

//

class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> ops;

        const int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
            } else if (isdigit(s[i])) {
                int j = i;
                while (j < n && isdigit(s[j])) ++j;
                int num = stoi(s.substr(i, j - i));
                nums.push_back(num);
                i = j;

                if (!ops.empty()) {
                    char op = ops.back();
                    if (op == '*' || op == '/') {
                        ops.pop_back();

                        int rhs = nums.back();
                        nums.pop_back();
                        int lhs = nums.back();
                        nums.pop_back();
                        int res = op == '*' ? lhs * rhs : lhs / rhs;
                        nums.push_back(res);
                    }
                }
            } else {
                ops.push_back(s[i]);
                ++i;
            }
        }

        int res = nums[0];
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == '+') {
                res += nums[i + 1];
            } else {
                res -= nums[i + 1];
            }
        }

        return res;
    }
};

//

class Solution {
public:
    int calculate(string s) {
        vector<int> nums;

        const int n = s.size();
        int i = 0;
        char op = '+';
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
            } else if (isdigit(s[i])) {
                int j = i;
                while (j < n && isdigit(s[j])) ++j;
                int num = stoi(s.substr(i, j - i));

                if (op == '*') {
                    nums.back() *= num;
                } else if (op == '/') {
                    nums.back() /= num;
                } else {
                    nums.push_back(op == '+' ? num : -num);
                }
                i = j;
            } else {
                op = s[i];
                ++i;
            }
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};

//

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int lhs = 0;

        const int n = s.size();
        int i = 0;
        char op = '+';
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
            } else if (isdigit(s[i])) {
                int j = i;
                while (j < n && isdigit(s[j])) ++j;
                int num = stoi(s.substr(i, j - i));

                if (op == '*') {
                    lhs *= num;
                } else if (op == '/') {
                    lhs /= num;
                } else {
                    res += lhs;
                    lhs = op == '+' ? num : -num;
                }
                i = j;
            } else {
                op = s[i];
                ++i;
            }
        }

        res += lhs;
        return res;
    }
};
