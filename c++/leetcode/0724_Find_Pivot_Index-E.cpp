class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0, rsum = sum;
        for (int i = 0; i < nums.size(); ++i) {
            rsum -= nums[i];
            if (lsum == rsum) return i;
            lsum += nums[i];
        }
        return -1;
    }
};
