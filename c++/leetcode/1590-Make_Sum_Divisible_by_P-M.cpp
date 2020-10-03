class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int n = nums.size();
        int res = n + 1;
        
        unordered_map<int, int> rem;
        rem[0] = -1;
        
        auto sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        int total_rem = sum % p;
        if (total_rem == 0) return 0;
        
        auto cur_sum = 0;
        for (int i = 0; i < n; ++i) {
            cur_sum += nums[i];
            int cur_rem = cur_sum % p;
            int target_rem = (cur_rem - total_rem + p) % p;
            if (rem.count(target_rem)) {
                res = min(res, i - rem[target_rem]);
            }
            rem[cur_rem] = i;
            cur_sum = cur_rem;
        }
        
        return res < n ? res : -1;
    }
};
