class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (const auto n : nums) num ^= n;
        return num;
    }
};