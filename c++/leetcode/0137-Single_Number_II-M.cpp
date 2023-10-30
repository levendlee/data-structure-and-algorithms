// 137 Single Number II
// https://leetcode.com/problems/single-number-ii

// version: 1; create time: 2020-02-02 14:24:51;
class Solution {
public:
    // Overall idea: 1) using XOR as 1 bit adder.
    //               2) using AND as the carry calculator.
    //               3) using mask and AND to mod the times

    int singleNumber(vector<int>& nums) {
        int x0 = 0, x1 = 0, mask;
        for (const auto n : nums) {
            x1 ^= (x0 & n); // the msb of the counter which counts the occurrence of 1s.
            x0 ^= n;        // the lsb of the counter which counts the occurrence of 1s.
            mask = ~(x1 & x0);  // the mask to reset to zero when the counter reaches 3
            x1 &= mask;     // reset
            x0 &= mask;     // reset
        }
        return x0;
    }
};

// 2023/10/29

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int bit = 0; bit < 32; ++bit) {
            int sum = 0;
            for (int n : nums) {
                sum += (n >> bit) & 0x1;
            }
            res |= (sum % 3) << bit;
        }

        return res;
    }
};
