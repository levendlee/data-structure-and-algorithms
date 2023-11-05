// 13 Roman to Integer
// https://leetcode.com/problems/roman-to-integer

// version: 1; create time: 2020-02-10 13:24:20;
class Solution {
public:
    int romanToInt(string s) {
        int num = 0;

        int i = 0;
        auto calc = [&](char c0, int n0, char c1, int n1) {
            while (s.find(c0, i) != string::npos) {
                int j = s.find(c0, i);
                num += n0;
                if (j - 1 >= 0 && s[j-1] ==c1) {
                    num -= n1;
                }
                i = j + 1;
            }
        };

        calc('M', 1000, 'C', 100);
        calc('D', 500, 'C', 100);
        calc('C', 100, 'X', 10);
        calc('L', 50, 'X', 10);
        calc('X', 10, 'I', 1);
        calc('V', 5, 'I', 1);
        calc('I', 1, '#', 0);
        return num;
    }
};

// 2023/11/04

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> lookup = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int number = 0;
        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            int value = lookup[s[i]];
            if (i < n - 1 && lookup[s[i + 1]] > value) {
                number -= value;
            } else {
                number += value;
            }
        }
        return number;
    }
};
