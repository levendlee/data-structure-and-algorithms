// 118 Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle

// version: 1; create time: 2020-02-01 21:21:31;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if (numRows == 0) return res;
        res[0] = {1};
        for (int i = 1; i < numRows; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                res[i].push_back((j == 0 ? 0 : res[i-1][j-1]) + (j == i ? 0 : res[i-1][j]));
            }
        }
        return res;
    }
};
