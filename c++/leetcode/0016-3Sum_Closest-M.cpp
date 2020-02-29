// 16 3Sum Closest
// https://leetcode.com/problems/3sum-closest

// version: 1; create time: 2020-01-26 21:18:44;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int n = nums.size();

        // O(N^2logN)
        /*
        set<int> bst;
        int closest = nums[0] + nums[1] + nums[2];

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                bst.insert(nums[i] + nums[j]);
            }
            for (int k = j + 1; k < n; ++k) {
                int rem = target - nums[k];
                auto iter = bst.lower_bound(rem);
                if (iter != bst.end() && (abs(*iter + nums[k] - target) < abs(closest - target))) {
                    closest = *iter + nums[k];
                }
                if (iter != bst.begin() && (abs(*--iter + nums[k] - target) < abs(closest - target))) {
                    closest = *iter + nums[k];
                }
                if (closest == target) {
                    return closest;
                }
            }
        }
        */
        int larger = INT_MAX;
        int smaller = INT_MAX;
        std::sort(nums.begin(), nums.end());
        for (int j = 1; j < n; ++j) {
            int k = n - 1;
            for (int i = 0; i < j; ++i) {
                int left = nums[i] + nums[j];
                while (k > j && (left + nums[k] > target)) {
                    larger = std::min(larger, left + nums[k] - target);
                    --k;
                }
                if (k > j && (left + nums[k] <= target)) {
                    smaller = std::min(smaller, target - left - nums[k]);
                }
            }
        }
        return larger < smaller ? target + larger : target - smaller;
    }
};
