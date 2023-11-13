class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        for (int i = 0; i < 32; ++i) {
            int ba = (a >> i) & 0x1;
            int bb = (b >> i) & 0x1;
            int bc = (c >> i) & 0x1;

            flips += (ba | bb) ^ bc;
            flips += ba & bb && !bc;
        }

        return flips;
    }
};
