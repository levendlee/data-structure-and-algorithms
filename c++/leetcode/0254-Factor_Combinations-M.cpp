// 254 Factor Combinations
// https://leetcode.com/problems/factor-combinations

// version: 1; create time: 2020-02-08 21:13:11;
class Solution {
public:
    void findFactors(vector<vector<int>>& res, vector<int>& cur, int n) {
        if (n == 1 && cur.size() > 1) {
            res.push_back(cur);
            return;
        }

        int start = cur.empty() ? 2 : cur.back();
        for (int i = start; i <= n; ++i) {
            if (n % i == 0) {
                cur.push_back(i);
                findFactors(res, cur, n / i);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> cur;
        findFactors(res, cur, n);
        return res;
    }
};
