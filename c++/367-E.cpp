class Solution {
public:
    bool isPerfectSquare(int num) {
        long i = 1;
        while (true) {
            auto sq = i * i;
            if (sq == num) return true;
            if (sq > num) return false;
            ++i;
        }
        return false;
    }
};