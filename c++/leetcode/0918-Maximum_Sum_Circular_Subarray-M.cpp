class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();

        int64_t total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int64_t max_sum = INT_MIN, min_sum = INT_MAX;
        int64_t cur_max_sum = INT_MIN, cur_min_sum = INT_MAX, min_included = 0;
        for (int num : nums) {
            if (cur_max_sum < 0) {
                cur_max_sum = 0;
            }
            cur_max_sum += num;
            if (cur_min_sum > 0) {
                cur_min_sum = 0;
                min_included = 0;
            }
            cur_min_sum += num;
            ++min_included;
            max_sum = max(max_sum, cur_max_sum);
            if (min_included != n) {
                min_sum = min(min_sum, cur_min_sum);
            }
        }

        return max(max_sum, total_sum - min_sum);
    }
};
