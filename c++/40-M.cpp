class Solution {
public:
    void findComb(vector<vector<int>>& res, vector<int>& cur, const int sum, const int target, const vector<int>& candidates, const int idx) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(cur);
        } else {
            int i = idx;
            while (i < candidates.size()) {
                cur.push_back(candidates[i]);
                findComb(res, cur, sum + candidates[i], target, candidates, i + 1);
                while (i + 1 < candidates.size() && candidates[i] == candidates[i+1]) ++i;
                ++i;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        findComb(res, cur, 0, target, candidates, 0);
        return res;
    }
};