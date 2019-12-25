class Solution {
public:
    int brokenCalc(int X, int Y) {
        int steps = 0;
        while (Y != X) {
            if (Y < X || Y % 2) {
                Y += 1;
            } else {
                Y /= 2;
            }
            ++steps;
        }
        return steps;
    }
};