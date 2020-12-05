class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();
        unordered_map<int, int> sums_map;
        int lsum = 0;
        sums_map[0] = 0;
        for (int i = 0; i < n; ++i) {
            lsum += nums[i];
            sums_map[lsum] = i + 1;
        }
        int res = n + 1;
        int rsum = 0;
        for (int i = n - 1; i >= 0; --i) {
            rsum += nums[i];
            if (sums_map.count(x - rsum)) {
                res = min(res, n - i + sums_map[x - rsum]);
            }
        }
        if (sums_map.count(x)) {
            res = min(res, sums_map[x]);
        }
        return res <= n ? res : -1;
    }
};
