class Solution {
public:
    void comb(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int idx) {
        if (idx == tmp.size()) {
            res.push_back(tmp);
            return;
        }
        for (auto& n : nums) {
            if (n == -1) continue;
            if (idx > 0 && tmp[idx - 1] >= n) continue;
            tmp[idx] = n;
            auto t = -1;
            std::swap(t, n);
            comb(res, nums, tmp, idx + 1);
            std::swap(t, n);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        vector<int> nums(n, 0);
        std::iota(nums.begin(), nums.end(), 1);

        vector<int> tmp(k, 0);
        comb(res, nums, tmp, 0);

        return res;
    }
};