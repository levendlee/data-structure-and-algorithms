class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        const int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            i = j;
            while ((j + 1 < n) && (nums[j + 1] == nums[j] + 1)) ++j;
            if (i == j) {
                ranges.push_back(to_string(nums[j]));
            } else {
                ranges.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            ++j;
        }

        return ranges;
    }
};
