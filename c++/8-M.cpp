class Solution {
public:
    int myAtoi(string str) {
        const int n = str.size();

        int i = 0, j = n - 1;
        while (i < n && str[i] == ' ') ++i;
        while (j >= i && str[j] == ' ') --j;
        if (i > j) return 0;

        int sign = 1;
        if (str[i] == '+' || str[i] == '-') {
            sign *= str[i] == '+' ? 1 : -1;
            ++i;
        }
        if (i > j) return 0;

        long num = 0;
        while (i <= j) {
            if (!isdigit(str[i])) return num * sign;
            num = num * 10 + (str[i] - '0');
            if (num * sign > INT_MAX) return INT_MAX;
            if (num * sign < INT_MIN) return INT_MIN;
            ++i;
        }

        return num * sign;
    }
};