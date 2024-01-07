// 273 Integer to English Words
// https://leetcode.com/problems/integer-to-english-words

// version: 1; create time: 2020-01-16 00:04:10;
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

//

class Solution {
public:
    Solution() {
        number_dict = {
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},

            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
            
            {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
            {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
        };
    }
    string numberToWords(int num) {
        constexpr int kMillion = 1000 * 1000;
        constexpr int kBillion = 1000 * 1000 * 1000;



        function<std::string(int)> to_words;
        auto to_reminder = [&](int rem) -> std::string {
            if (rem) {
                return " " + to_words(rem);
            }
            return "";
        };

        to_words = [&](int num) -> std::string {
            if (num == 0) {
                return "";
            } else if (num <= 20) {
                return number_dict.at(num);
            } else if (num < 100) {
                return number_dict.at(num - num % 10) + to_reminder(num % 10);
            } else if (num < 1000) {
                return number_dict.at(num / 100) + " Hundred" + to_reminder(num % 100);
            } else if (num < kMillion) {
                return to_words(num / 1000) + " Thousand" + to_reminder(num % 1000);
            } else if (num < kBillion) {
                return to_words(num / kMillion) + " Million" + to_reminder(num % kMillion);
            } else {
                return to_words(num/ kBillion) + " Billion" + to_reminder(num % kBillion);
            }
        };

        if (num == 0) return "Zero";

        return to_words(num);
    }
private:
    unordered_map<int, std::string> number_dict;
};