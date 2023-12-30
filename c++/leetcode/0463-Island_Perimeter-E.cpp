// 463 Island Perimeter
// https://leetcode.com/problems/island-perimeter

// version: 1; create time: 2020-02-08 15:48:08;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    constexpr int offsets[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                    for (int k = 0; k < 4; ++k) {
                        int ii = offsets[k][0] + i;
                        int jj = offsets[k][1] + j;
                        if (ii < 0 || ii >= grid.size() || jj < 0 || jj >= grid[0].size()) {
                            ++perimeter;
                        } else {
                            perimeter += grid[ii][jj] != 1;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};

//

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        function<int(int, int)> dfs;
        dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
                return 1;
            }
            if (grid[i][j] == -1) {
                return 0;
            }
            grid[i][j] = -1;
            constexpr int offsets[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            int sum = 0;
            for (int k = 0; k < 4; ++k) {
                sum += dfs(i + offsets[k][0], j + offsets[k][1]);
            }
            return sum;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }
};

//

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        int perimeter = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    if (i == 0 || grid[i - 1][j] == 0) ++perimeter;
                    if (i == m - 1 || grid[i + 1][j] == 0) ++perimeter;
                    if (j == 0 || grid[i][j - 1] == 0) ++perimeter;
                    if (j == n - 1 || grid[i][j + 1] == 0) ++ perimeter;
                }
            }
        }
        return perimeter;
    }
};
