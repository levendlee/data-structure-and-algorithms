class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        int to_spread = 0;
        queue<pair<int, int>> bfs;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cell = grid[i][j];
                if (cell == 1) {
                    ++to_spread;
                } else if (cell == 2) {
                    bfs.push({i, j});
                }
            }
        }

        constexpr int delta[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int steps = 0;
        while (!bfs.empty()) {
            if (to_spread == 0) break;
            int search_size = bfs.size();
            ++steps;
            for (int k = 0; k < search_size; ++k) {
                auto [i, j] = bfs.front();
                bfs.pop();
                for (auto [di, dj] : delta) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != 1) continue;
                    grid[ni][nj] = 2;
                    --to_spread;
                    bfs.push({ni, nj});
                }
            }
        }

        return to_spread ? -1 : steps;
    }
};
