// 41 First Missing Positive
// https://leetcode.com/problems/first-missing-positive

// version: 1; create time: 2020-01-18 18:50:58;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        for (auto& number : nums) {
            if (number > n || number <= 0) {
                number = n + 1;
            }
        }
        for (auto& number : nums) {
            if (abs(number) <= n) {
                nums[abs(number) - 1] = -abs(nums[abs(number) - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
