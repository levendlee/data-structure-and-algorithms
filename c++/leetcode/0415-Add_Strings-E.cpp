// 415 Add Strings
// https://leetcode.com/problems/add-strings

// version: 1; create time: 2020-02-05 20:47:48;
class Solution {
public:
    string addStrings(string num1, string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        string res;
        const int n1 = num1.size();
        const int n2 = num2.size();
        int i = 0, j = 0, c = 0;
        while (i < n1 || j < n2 || c) {
            auto lhs = i < n1 ? num1[i++] - '0' : 0;
            auto rhs = j < n2 ? num2[j++] - '0' : 0;
            int sum = lhs + rhs + c;
            res.push_back(sum % 10 + '0');
            c = sum / 10;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
