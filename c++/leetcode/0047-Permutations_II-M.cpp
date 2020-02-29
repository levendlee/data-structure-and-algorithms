// 47 Permutations II
// https://leetcode.com/problems/permutations-ii

// version: 1; create time: 2020-02-09 23:29:16;
class Solution {
public:
    void getPerms(vector<vector<int>>& perms, vector<int>& cur, unordered_map<int, int>& cnts, const int n) {
        if (cur.size() == n) {
            perms.push_back(cur);
        } else {
            for (auto& p : cnts) {
                if (p.second == 0) continue;
                --p.second;
                cur.push_back(p.first);
                getPerms(perms, cur, cnts, n);
                cur.pop_back();
                ++p.second;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (const auto n : nums) {
            ++cnts[n];
        }

        vector<vector<int>> perms;
        vector<int> cur;
        getPerms(perms, cur, cnts, nums.size());
        return perms;
    }
};
