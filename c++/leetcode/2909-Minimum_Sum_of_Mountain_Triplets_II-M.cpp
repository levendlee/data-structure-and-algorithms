class Solution {
public:
    int minimumSum(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        const int n = nums.size();
        vector<int> lmin(n);
        lmin[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            lmin[i] = std::min(lmin[i - 1], nums[i]);
        }

        int min_sum = INT_MAX;
        int rmin = nums[n - 1];
        for (int i = n - 2; i >= 1; --i) {
            if (lmin[i - 1] < nums[i] && rmin < nums[i]) {
                min_sum = std::min(lmin[i - 1] + nums[i] + rmin, min_sum);
            }
            rmin = std::min(rmin, nums[i]);
        }

        return min_sum == INT_MAX ? -1 : min_sum;
        
    }
};

