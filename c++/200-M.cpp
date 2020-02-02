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