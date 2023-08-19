class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        std::map<int, int> num_counts;
        for (const int n : nums) {
            num_counts[n] += 1;
        }
        int num_ops = 0;
        int idx = 0;
        for (const auto&[n, cnt] : num_counts) {
            num_ops += cnt * idx++;
        }
        return num_ops;
    }
};
