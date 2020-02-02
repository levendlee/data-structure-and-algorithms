class Solution {
public:
    int reverse(int x) {
        long input = x;
        input = abs(input);
        long output = 0;
        while (input) {
            output *= 10;
            output += input % 10;
            input /= 10;
        }
        output = x > 0 ? output : -output;
        return output > INT_MAX ? 0 : (output < INT_MIN ? 0 : output);
    }
};