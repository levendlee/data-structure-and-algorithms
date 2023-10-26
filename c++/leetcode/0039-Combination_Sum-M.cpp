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

// 2023/10/23

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;

        sort(candidates.begin(), candidates.end());
        function<void(int, int, vector<int>&)> backtracing;
        backtracing = [&](int total, int idx, vector<int>& nums) {
            if (total == target) {
                results.push_back(nums);
                return;
            } else if (total > target) {
                return;
            }

            for (int i = idx; i < candidates.size(); ++i) {
                int n = candidates[i];
                if (total + n > target) break;
                total += n;
                nums.push_back(n);
                backtracing(total, i, nums);
                total -= n;
                nums.pop_back();
            }
        };
        vector<int> nums;
        backtracing(0, 0, nums);

        return results;
    }
};
