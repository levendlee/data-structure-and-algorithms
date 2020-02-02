class Solution {
public:
    void getPermute(vector<vector<int>>& res, vector<int>& cur, vector<bool>& used, const vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (used[i]) continue;
                used[i] = true;
                cur.push_back(nums[i]);
                getPermute(res, cur, used, nums);
                used[i] = false;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        getPermute(res, cur, used, nums);
        return res;
    }
};