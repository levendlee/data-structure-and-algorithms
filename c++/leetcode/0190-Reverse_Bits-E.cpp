class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        for (int shift = 0; shift < 32; ++shift) {
            res = res << 1;
            res |= (n >> shift) & 0x1;
        }
        return res;
    }
};
