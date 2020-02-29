// 66 Plus One
// https://leetcode.com/problems/plus-one

// version: 1; create time: 2020-02-01 15:20:29;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::reverse(digits.begin(), digits.end());
        const int n = digits.size();
        int carry = 1;
        for (int i = 0; i < n; ++i) {
            int sum = carry + digits[i];
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0) break;
        }
        if (carry) digits.push_back(carry);
        std::reverse(digits.begin(), digits.end());
        return digits;
    }
};
