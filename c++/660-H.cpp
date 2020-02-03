class Solution {
public:
    int newInteger(int n) {
        string res;
        while (n) {
            char c = '0' + n % 9;
            res = c + res;
            n /= 9;
        }
        return stoi(res);
    }
};