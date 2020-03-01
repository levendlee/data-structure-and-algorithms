// 1351 Count Negative Numbers in a Sorted Matrix
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

// version: 1; create time: 2020-02-29 22:27:10;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (const auto& row : grid) {
            cnt += std::lower_bound(row.rbegin(), row.rend(), 0) - row.rbegin();
        }
        return cnt;
    }
};
