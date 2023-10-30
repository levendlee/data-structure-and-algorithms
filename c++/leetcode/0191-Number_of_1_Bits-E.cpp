class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int shift = 0; shift < 32; ++shift) {
            res += (n >> shift) & 0x1;
        }
        return res;
    }
};
