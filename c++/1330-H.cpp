class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        const int n = nums.size();
        int value = 0;
        for (int i = 0; i < n - 1; ++i) {
            value += abs(nums[i] - nums[i+1]);
        }

        int diff = 0;
        int high = INT_MIN;
        int low = INT_MAX;
        for (int i = 0; i < n - 1; ++i) {
            diff = std::max(diff, std::max(abs(nums[0] - nums[i+1]) - abs(nums[i] - nums[i+1]),
                                           abs(nums[n-1] - nums[i]) - abs(nums[i+1] - nums[i])));
            high = std::max(high, std::min(nums[i], nums[i+1]));
            low = std::min(low, std::max(nums[i], nums[i+1]));
        }

        return value + std::max(diff, (high - low) * 2);
    }
};