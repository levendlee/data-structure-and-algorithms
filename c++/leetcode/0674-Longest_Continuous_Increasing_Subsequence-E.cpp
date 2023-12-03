// 674 Longest Continuous Increasing Subsequence
// https://leetcode.com/problems/longest-continuous-increasing-subsequence

// version: 1; create time: 2020-01-23 23:25:07;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;

        int max_len = 1;
        int cur_len = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                max_len = std::max(max_len, ++cur_len);
            } else {
                cur_len = 1;
            }
        }
        return max_len;
    }
};

//

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 1, max_len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                max_len = max(max_len, ++len);
            } else {
                len = 1;
            }
        }
        return max_len;
    }
};
