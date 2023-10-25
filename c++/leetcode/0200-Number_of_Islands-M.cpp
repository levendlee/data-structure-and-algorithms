// 200 Number of Islands
// https://leetcode.com/problems/number-of-islands

// version: 1; create time: 2020-02-02 14:10:09;
class Solution {
private:
    int m_;
    int n_;

public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        constexpr int offsets[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int k = 0; k < 4; ++k) {
            const int ni = i + offsets[k][0];
            const int nj = j + offsets[k][1];
            if (ni < 0 || ni >= m_ || nj < 0 || nj >= n_ || grid[ni][nj] == '0') continue;
            grid[ni][nj] = '0';
            dfs(grid, ni, nj);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m_ = grid.size();
        if (m_ == 0) return 0;
        n_ = grid[0].size();
        if (n_ == 0) return 0;

        int cnt = 0;
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                }
            }
        }

        return cnt;
    }
};

// 2023/10/21

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size();
        if (m == 0) return 0;
        const int n = grid[0].size();
        if (n == 0) return 0;

        int num_islands = 0;
        std::function<void(int, int)> dfs;
        dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
                return;
            }
            grid[i][j] = '0';
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '1') continue;
                ++num_islands;
                dfs(i, j);
            }
        }

        return num_islands;
    }
};
