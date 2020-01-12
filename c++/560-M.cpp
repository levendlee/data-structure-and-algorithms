class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        sums[0] = 1;
        int acc = 0;
        long total_cnts = 0;
        for (const auto& num : nums) {
            acc += num;
            const auto target = acc - k;
            if (sums.count(target)) {
                total_cnts += sums[target];
            }
            ++sums[acc];
        }
        return total_cnts;
    }
};