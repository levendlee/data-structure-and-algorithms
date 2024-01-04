class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int ops = 0;
        while (i < j) {
            int64_t lhs = nums[i];
            int64_t rhs = nums[j];
            while (i < j && lhs != rhs) {
                if (lhs < rhs) {
                    lhs += nums[++i];
                    ++ops;
                } else {
                    rhs += nums[--j];
                    ++ops;
                }
            }
            ++i;
            --j;
        }
        return ops;
    }
};
