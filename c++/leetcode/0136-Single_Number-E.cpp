// 136 Single Number
// https://leetcode.com/problems/single-number

// version: 1; create time: 2020-02-01 17:07:01;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (const auto n : nums) num ^= n;
        return num;
    }
};

// 2023/10/29

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            res ^= n;
        }
        return res;
    }
};
