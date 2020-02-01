class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        
        const int half = sum / 2;
        vector<bool> mem(half, false);
        mem[0] = true;
        for (const auto& n : nums) {
            for (int i = half - 1; i >= 0; --i) {
                if (!mem[i]) continue;
                int s = i + n;
                if (s > half) continue;
                if (s == half) return true;
                mem[s] = true;
            }
        }
        return false;
    }
};