class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return -1;
        /*
        vector<int> rsum(n, 0);
        for (int i = n - 1; i > 0; --i) {
            rsum[i-1] = rsum[i] + nums[i];
        }
        int lsum = 0;
        if (rsum[0] == 0) return 0;
        for (int i = 0; i < n - 1; ++i) {
            lsum += nums[i];
            if (lsum == rsum[i + 1]) return i + 1;
        }
        */
        int lsum = 0, rsum = std::accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; ++i) {
            rsum -= nums[i];
            if (lsum == rsum) return i;
            lsum += nums[i];
        }
        return -1;
    }
};