// 994 Rotting Oranges
// https://leetcode.com/problems/rotting-oranges

// version: 1; create time: 2019-11-14 22:31:18;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0) return 0;
        const int n = grid[0].size();
        if (n == 0) return 0;

        std::queue<std::pair<int,int>> bfs;
        int num_fresh = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    num_fresh++;
                } else if (grid[i][j] == 2) {
                    bfs.push({i, j});
                }
            }
        }

        int num_hours = 0;
        while (num_fresh != 0 && !bfs.empty()) {
            const int size = bfs.size();
            for (int i = 0; i < size; ++i) {
                auto r = bfs.front(); bfs.pop();
                int x = r.first;
                int y = r.second;
                constexpr int offsets[][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
                for (int k = 0; k < 4; ++k) {
                    int xx = x + offsets[k][0];
                    int yy = y + offsets[k][1];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n) {
                        continue;
                    }
                    if (grid[xx][yy] == 1) {
                        grid[xx][yy] = 2;
                        num_fresh--;
                        bfs.push({xx, yy});
                    }
                }
            }
            num_hours++;
        }

        return num_fresh == 0 ? num_hours : -1;
    }
};
