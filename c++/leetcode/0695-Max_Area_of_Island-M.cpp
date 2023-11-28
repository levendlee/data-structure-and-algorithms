class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        function<int(int, int)> dfs;
        dfs = [&](int i, int j) {
            if (!grid[i][j]) return 0;
            grid[i][j] = 0;
            int area = 1;
            constexpr int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int k = 0; k < 4; ++k) {
                int ii = i + offsets[k][0];
                int jj = j + offsets[k][1];
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || !grid[ii][jj]) continue;
                area += dfs(ii, jj);
            }
            return area;
        };

        int max_area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                max_area = max(max_area, dfs(i, j));
            }
        }
        return max_area;
    }
};
