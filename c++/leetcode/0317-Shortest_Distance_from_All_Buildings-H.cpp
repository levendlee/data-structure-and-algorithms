class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        auto bfs_search = [&](int i, int j) {
            queue<int> bfs;
            bfs.push(i * n + j);

            int steps = 0;
            while (!bfs.empty()) {
                int search_space = bfs.size();
                ++steps;
                for (int k = 0; k < search_space; ++k) {
                    int ij = bfs.front();
                    bfs.pop();
                    int i = ij / n, j = ij % n;
                    constexpr int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for (int k = 0; k < 4; ++k) {
                        int ii = i + offsets[k][0], jj = j + offsets[k][1];
                        if (ii < 0 || ii >= m || jj < 0 || jj >= n || grid[ii][jj] != 0) continue;
                        grid[ii][jj] = -steps;
                        bfs.push({ii * n + jj});
                    }
                }
            }
        };

        vector<int> total_dist(m * n, 0);
        auto postprocess_bfs = [&] () {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] < 0) {
                        total_dist[i * n + j] += -grid[i][j];
                        grid[i][j] = 0;
                    } else if (grid[i][j] == 0) {
                        total_dist[i * n + j] = INT_MAX;
                        grid[i][j] = INT_MAX;
                    } else {
                        total_dist[i * n + j] = INT_MAX;
                    }
                }
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    bfs_search(i, j);
                    postprocess_bfs();
                }
            }
        }

        int min_dist = *min_element(total_dist.begin(), total_dist.end());
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};
