// 18 4Sum
// https://leetcode.com/problems/4sum

// version: 1; create time: 2020-02-01 20:04:44;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        const int n = nums.size();
        if (n < 4) return res;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int ntarget = target - (nums[i] + nums[j]);
                int k = j + 1, l = n - 1;
                while (k < l) {
                    int sum = nums[k] + nums[l];
                    if (sum == ntarget) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k + 1] == nums[k]) ++k;
                        ++k;
                        while (k < l && nums[l - 1] == nums[l]) --l;
                        --l;
                    } else if (sum > ntarget) {
                        while (k < l && nums[l - 1] == nums[l]) --l;
                        --l;
                    } else {
                        while (k < l && nums[k + 1] == nums[k]) ++k;
                        ++k;
                    }
                }
            }
        }
        return res;
    }
};
