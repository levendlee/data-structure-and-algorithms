class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0];

        int hpre2 = 0, hpre1 = 0;
        int pre2 = 0, pre1 = 0;
        for (int i = 0; i < n; ++i) {
            int hcur = std::max(hpre1, hpre2 + nums[i]);
            hpre2 = hpre1; hpre1 = hcur;
            if (i == 0) continue;
            int cur = std::max(pre1, pre2 + nums[i]);
            pre2 = pre1; pre1 = cur;
        }
        return std::max(pre1, hpre2);
    }
};