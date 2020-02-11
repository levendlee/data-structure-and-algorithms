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