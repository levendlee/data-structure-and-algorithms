class Solution {
private:
    int countPairs(const vector<int>& nums, int diff, int limit) {
        const int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += std::upper_bound(nums.begin() + i,  nums.end(), nums[i] + diff) - nums.begin() - i - 1;
            if (cnt > limit) break;
        }
        return cnt;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int lo = 0, hi = *std::max_element(nums.begin(), nums.end()) - *std::min_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = countPairs(nums, mid, k);
            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};