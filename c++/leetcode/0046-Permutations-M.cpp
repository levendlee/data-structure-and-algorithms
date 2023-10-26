// 46 Permutations
// https://leetcode.com/problems/permutations

// version: 1; create time: 2020-02-01 19:32:36;
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

// 2023/10/23

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();

        vector<bool> used(n, false);
        vector<vector<int>> results;
        vector<int> perm;

        function<void()> dfs;
        dfs = [&]() {
            if (perm.size() == n) {
                results.push_back(perm);
            }
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    used[i] = true;
                    perm.push_back(nums[i]);
                    dfs();
                    perm.pop_back();
                    used[i] = false;
                }
            }
        };
        dfs();

        return results;
    }
};
