// 77 Combinations
// https://leetcode.com/problems/combinations

// version: 1; create time: 2020-01-30 20:59:42;
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

// 2023/10/23
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;

        function<void(int i, vector<int>&)> dfs;
        dfs = [&](int i, vector<int>& vec) {
            if (vec.size() == k) {
                results.push_back(vec);
                return;
            }
            for (int num = i; num <= n; ++num) {
                vec.push_back(num);
                dfs(num + 1, vec);
                vec.pop_back();
            }
        };
        vector<int> vec;
        dfs(1, vec);
        return results;
    }
};
