// 442 Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array

// version: 1; create time: 2020-02-11 18:25:30;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        const int n = nums.size();
        for (const auto& num : nums) {
            nums[(num - 1) % n] += n;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 2 * n) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
