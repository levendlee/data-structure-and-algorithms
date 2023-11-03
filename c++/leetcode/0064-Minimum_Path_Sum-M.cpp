// 64 Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum

// version: 1; create time: 2020-01-27 23:11:37;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0) return 0;
        const int n = grid[0].size();
        if (n == 0) return 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                const auto left = i == 0 ? INT_MAX : grid[i-1][j];
                const auto up = j == 0 ? INT_MAX : grid[i][j-1];
                grid[i][j] += std::min(left, up);
            }
        }
        return grid[m-1][n-1];
    }
};

// 2023/11/01

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                grid[i][j] += std::min(i == 0 ? INT_MAX : grid[i - 1][j],
                                       j == 0 ? INT_MAX : grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};
