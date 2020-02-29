// 229 Majority Element II
// https://leetcode.com/problems/majority-element-ii

// version: 1; create time: 2020-02-11 19:30:30;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty()) return {};
        bool fill1 = false; int num1 = INT_MIN, cnt1 = 0;
        bool fill2 = false; int num2 = INT_MIN, cnt2 = 0;
        for (const auto& n : nums) {
            if (fill1 && n == num1) {
                ++cnt1;
            } else if (fill2 && n == num2) {
                ++cnt2;
            } else if (cnt1 == 0) {
                num1 = n;
                cnt1 = 1;
                fill1 = true;
            } else if (cnt2 == 0) {
                num2 = n;
                cnt2 = 1;
                fill2 = true;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        vector<int> res;
        if (fill1 && count(nums.begin(), nums.end(), num1) > nums.size() / 3) {
            res.push_back(num1);
        }
        if (fill2 && count(nums.begin(), nums.end(), num2) > nums.size() / 3) {
            res.push_back(num2);
        }
        return res;
    }
};
