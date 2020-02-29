// 334 Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence

// version: 1; create time: 2019-10-30 23:40:00;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num0 = INT_MAX;
        int num1 = INT_MAX;
        for (auto& n : nums) {
            if (n > num1) {
                return true;
            } else if (n > num0) {
                num1 = n;
            } else {
                num0 = n;
            }
        }
        return false;
    }
};
