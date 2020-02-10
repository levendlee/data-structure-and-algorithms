class Solution {
private:
    // Time Complexity O(k^N) -> (Optimized to) O(k^(N-k) * k!)
    // Space Complexity O(N)
    bool search(vector<int>& groups, const int target, const vector<int>& nums, const int i) {
        if (i == nums.size()) return true;
        for (auto& g : groups) {
            if (g + nums[i] <= target) {
                g += nums[i];
                if (search(groups, target, nums, i + 1)) return true;
                g -= nums[i];
            }
            if (g == 0) break;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;

        vector<int> groups(k, 0);
        const int target = sum / k;

        sort(nums.begin(), nums.end(), greater<int>());
        return search(groups, target, nums, 0);
    }
};