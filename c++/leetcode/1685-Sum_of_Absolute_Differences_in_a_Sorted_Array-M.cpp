class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int n = nums.size();
        vector<int> sums(nums);
        for (int i = 1; i < n; ++i) {
            sums[i] += sums[i - 1];
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            const int lsum = sums[i];
            const int rsum = sums[n - 1] - sums[i];
            res[i] = (2*i + 2 - n) * nums[i] - lsum + rsum;
        }
        return res;
    }
};
