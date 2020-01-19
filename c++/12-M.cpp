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