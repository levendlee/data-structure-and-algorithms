// 15 3Sum
// https://leetcode.com/problems/3sum

// version: 1; create time: 2020-01-07 23:25:01;
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

// 2023/09/28

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> combos;
        const int n = nums.size();

        int i = 0, j, k;
        while (i < n - 2) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                const int two_sum = nums[j] + nums[k];
                if (two_sum == -nums[i]) {
                    combos.push_back({nums[i], nums[j], nums[k]});
                }
                if (two_sum <= -nums[i]) {
                    while ((j + 1 <= k) && (nums[j] == nums[++j]));
                }
                if (two_sum >= -nums[i]) {
                    while ((k - 1 >= j) && (nums[k] == nums[--k]));
                }
            }
            while ((i < n - 2) && (nums[i] == nums[++i]));
        }
        return combos;
    }
};
