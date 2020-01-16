class Solution {
public:
    string numberToWords(int num) {
        constexpr int billion = 1e9;
        constexpr int million = 1e6;
        constexpr int thousand = 1e3;
        constexpr int hundred = 1e2;

        const auto toWords = [&](const int unit_num, const string& unit_str) {
            auto res = numberToWords(num / unit_num) + " " + unit_str;
            if (num % unit_num) {
                return res + " " + numberToWords(num % unit_num);
            } else {
                return res;
            }
        };

        if (num >= billion) {
            return toWords(billion, "Billion");
        } else if (num >= million) {
            return toWords(million, "Million");
        } else if (num >= thousand) {
            return toWords(thousand, "Thousand");
        } else if (num >= hundred) {
            return toWords(hundred, "Hundred");
        } else if (num >= 10) {
            if (num < 20) {
                constexpr char numbers[10][10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
                return numbers[num - 10];
            } else {
                string res;
                constexpr char numbers[10][10] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
                res = numbers[num / 10 - 2];
                if (num % 10) {
                    return res + " " + numberToWords(num % 10);
                } else {
                    return res;
                }
            }
        } else {
            constexpr char numbers[10][10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
            return numbers[num];
        }
    }
};