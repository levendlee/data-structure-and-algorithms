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