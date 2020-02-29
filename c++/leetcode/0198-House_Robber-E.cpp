// 198 House Robber
// https://leetcode.com/problems/house-robber

// version: 1; create time: 2020-01-26 22:28:34;
public:
    int rob(vector<int>& nums) {
        int pre2 = 0;
        int pre1 = 0;
        for (const auto& n : nums) {
            int cur = std::max(pre1, pre2 + n);
            pre2 = pre1;
            pre1 = cur;
        }
        return std::max(pre2, pre1);
    }
};
