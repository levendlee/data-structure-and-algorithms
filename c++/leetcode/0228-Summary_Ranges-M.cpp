// 228 Summary Ranges
// https://leetcode.com/problems/summary-ranges

// version: 1; create time: 2020-01-27 22:03:19;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 0) return {};

        vector<string> res;
        int i = 0, j = 1;
        while (j <= n) {
            if (j == n || nums[j] != nums[j-1] + 1) {
                string rng = std::to_string(nums[i]);
                if (i != j - 1) rng += "->" + std::to_string(nums[j-1]);
                res.push_back(rng);
                i = j;
            }
            ++j;
        }
        return res;
    }
};
