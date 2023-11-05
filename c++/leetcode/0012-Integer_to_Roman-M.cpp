// 12 Integer to Roman
// https://leetcode.com/problems/integer-to-roman

// version: 1; create time: 2020-01-19 16:59:56;
class Solution {
public:
    string intToRoman(int num) {
        const auto composeRoman = [&](const int& unit, const char& symbol) {
            const auto cur = num / unit;
            const auto rem = num % unit;
            return string(cur, symbol) + intToRoman(rem);
        };

        if (num >= 1000) {
            return composeRoman(1000, 'M');
        } else if (num >= 900) {
            return "CM" + intToRoman(num - 900);
        } else if (num >= 500) {
            return composeRoman(500, 'D');
        } else if (num >= 400) {
            return "CD" + intToRoman(num - 400);
        } else if (num >= 100) {
            return composeRoman(100, 'C');
        } else if (num >= 90) {
            return "XC" + intToRoman(num - 90);
        } else if (num >= 50) {
            return composeRoman(50, 'L');
        } else if (num >= 40) {
            return "XL" + intToRoman(num - 40);
        } else if (num >= 10) {
            return composeRoman(10, 'X');
        } else if (num == 9) {
            return "IX";
        } else if (num >= 5) {
            return composeRoman(5, 'V');
        } else {
            constexpr char lookup[5][4] = {"", "I", "II", "III", "IV"};
            return lookup[num];
        }
    }
};

// 2023/11/04

class Solution {
public:
    string intToRoman(int num) {
        int n = 7;
        int values[] = {1, 5, 10, 50, 100, 500, 1000};
        char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        string res;
        int i = 0;
        for (int base = 10; base <= 1000; base *= 10) {
            i += 2;
            int reminder = num % 10;
            num = num / 10;
            char c1 = symbols[i - 2], c2 = symbols[i - 1], c3 = symbols[i];
            if (reminder == 0) {
                continue;
            }
            else if (reminder < 4) {
                res += string(reminder, c1);
            }
            else if (reminder == 4) {
                res += c2;
                res += c1;
            }
            else if (reminder == 5) {
                res += c2;
            }
            else if (reminder < 9) {
                res += string(reminder - 5, c1) + c2;
            }
            else {
                res += c3;
                res += c1;
            }
        }

        if (num) {
            res += string(num, 'M');
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

