class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int j = i + 1, k = n - 1, target = -nums[i];
            while (j < k) {
                int sum2 = nums[j] + nums[k];
                if (sum2 > target) {
                    --k;
                } else if (sum2 < target) {
                    ++j;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    while (k > j && nums[k] == nums[k - 1]) --k;
                    ++j;
                    --k;
                }

            }
        }
        return res;
    }
};