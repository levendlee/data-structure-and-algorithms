class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        /*
        // T: O(NlogN). S: O(N).
        set<int> tree;
        int min_abs_diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= x) {
                tree.insert(nums[i - x]);
            }

            auto insert_result = tree.insert(nums[i]);
            if (!insert_result.second) return 0;
            auto iter = insert_result.first;
            if (iter != tree.begin()) {
                --iter;
                min_abs_diff = min(min_abs_diff, nums[i] - *iter);
                ++iter;
            }
            if (++iter != tree.end()) {
                min_abs_diff = min(min_abs_diff, *iter - nums[i]);
            }
            tree.erase(nums[i]);


        }
        return min_abs_diff;
        */
        // Modified. Same complexity.
        set<int> tree;
        int min_abs_diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= x) {
                tree.insert(nums[i - x]);
            }
            auto iter = tree.lower_bound(nums[i]);
            if (*iter == nums[i]) return 0;
            if (iter != tree.end()) {
                min_abs_diff = min(min_abs_diff, *iter - nums[i]);
            }
            if (iter != tree.begin()) {
                --iter;
                min_abs_diff = min(min_abs_diff, nums[i] - *iter);
            }

        }
        return min_abs_diff;
    }
};