class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return false;
        stack<pair<int, int>> ranges;
        for (int i = 0; i < n; ++i) {
            if (ranges.empty() || ranges.top().first > nums[i]) {
                ranges.emplace(nums[i], nums[i]);
            } else {
                // ranges.top().first <= nums[i]
                const int min = ranges.top().first;
                while (!ranges.empty() && ranges.top().second < nums[i]) {
                    ranges.pop();
                }
                if (!ranges.empty()) {
                    if (ranges.top().second > nums[i] && ranges.top().first < nums[i]) {
                        return true;
                    }
                }
                ranges.emplace(min, nums[i]);
            }
        }
        return false;
    }
};