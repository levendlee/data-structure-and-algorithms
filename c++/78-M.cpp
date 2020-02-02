class Solution {
public:
    void getSubsets(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, const int idx) {
        res.push_back(cur);
        const int n = nums.size();
        for (int i = idx; i < n; ++i) {
            cur.push_back(nums[i]);
            getSubsets(res, cur, nums, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        getSubsets(res, cur, nums, 0);
        return res;
    }
};