// 78 Subsets
// https://leetcode.com/problems/subsets

// version: 1; create time: 2020-02-01 22:44:22;
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

//

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        const int n = nums.size();
        function<void(int, vector<int>&)> backtracking;
        backtracking = [&](int i, vector<int>& vec) {
            res.push_back(vec);
            for (int j = i; j < n; ++j) {
                vec.push_back(nums[j]);
                backtracking(j + 1, vec);
                vec.pop_back();
            }
        };
        vector<int> vec;
        backtracking(0, vec);

        return res;
    }
};
