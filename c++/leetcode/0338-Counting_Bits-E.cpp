class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        vector<int> bits(n + 1, 0);
        bits[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int msb = i & (-i);
            bits[i] = bits[i - msb] + 1;
        }
        return bits;
    }
};
