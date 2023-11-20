// 1091 Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix

// version: 1; create time: 2019-12-25 16:02:37;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0) return -1;
        const int n = grid[0].size();
        if (n == 0) return -1;
        if (grid[0][0] || grid[m-1][n-1]) return -1;
        if (m-1 == 0 && n-1 == 0) return 1;

        std::queue<std::pair<int, int>> bfs;
        bfs.emplace(0, 0);
        int steps = 1;
        while (!bfs.empty()) {
            //std::cout << steps << "#\n";
            const int size = bfs.size();
            for (int i = 0; i < size; ++i) {
                constexpr int offsets[][2] = {{0,1},{0,-1},{1,0},{-1,0},
                                              {1,1},{-1,1},{1,-1},{-1,-1}};
                const auto x = bfs.front().first;
                const auto y = bfs.front().second;
                bfs.pop();
                for (int k = 0; k < 8; ++k) {
                    const int xx = x + offsets[k][0];
                    const int yy = y + offsets[k][1];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy]) {
                        continue;
                    }
                    if (xx == m-1 && yy == n-1) {
                        return steps + 1;
                    }
                    grid[xx][yy] = 1;
                    bfs.emplace(xx, yy);
                }
            }
            ++steps;
        }

        return -1;
    }
};

//

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();

        queue<pair<int, int>> bfs;
        if (grid[0][0] != 0) return -1;
        if (n == 1) return 1;

        int steps = 1;
        bfs.push({0, 0});

        while (!bfs.empty()) {
            int search_space = bfs.size();
            ++steps;
            for (int k = 0; k < search_space; ++k) {
                auto [i, j] = bfs.front();
                bfs.pop();
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <=1; ++dj) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni < 0 || ni >= n || nj < 0 || nj >= n || grid[ni][nj]) continue;
                        if (ni == n-1 && nj == n-1) return steps;
                        grid[ni][nj] = 1;
                        bfs.push({ni, nj});
                    }
                }
            }
        }

        return -1;
    }
};
