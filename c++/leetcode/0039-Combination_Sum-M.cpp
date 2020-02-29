// 39 Combination Sum
// https://leetcode.com/problems/combination-sum

// version: 1; create time: 2020-02-01 16:13:36;
class Solution {
public:
    void findComb(vector<vector<int>>& res, vector<int>& cur, int sum, int target, vector<int>& candidates, int i) {
        if (sum > target) {
            return;
        } else if (sum == target) {
            res.push_back(cur);
        } else {
            while (i < candidates.size()) {
                cur.push_back(candidates[i]);
                findComb(res, cur, sum + candidates[i], target, candidates, i);
                ++i;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        findComb(res, cur, 0, target, candidates, 0);
        return res;
    }
};
