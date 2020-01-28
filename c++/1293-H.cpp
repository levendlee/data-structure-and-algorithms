struct Node {
    int i;
    int j;
    int k;
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        if (m == 0) return -1;
        const int n = grid[0].size();
        if (n == 0) return -1;
        if (m == 1 && n == 1) return 0;

        vector<bool> visit(m*n*(k+1), false);

        int steps = 0;
        queue<Node> bfs;
        bfs.push({0, 0, 0});
        visit[0] = true;
        while (!bfs.empty()) {
            const int size = bfs.size();
            for (int l = 0; l < size; ++l) {
                const auto node = bfs.front(); bfs.pop();
                constexpr int offsets[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                for (int t = 0; t < 4; ++t) {
                    const int ni = node.i + offsets[t][0];
                    const int nj = node.j + offsets[t][1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (ni == m - 1 && nj == n - 1) return steps + 1;
                    const int nk = node.k + grid[ni][nj];
                    if (nk > k || visit[ni*n*(k+1) + nj*(k+1) + nk]) continue;
                    visit[ni*n*(k+1) + nj*(k+1) + nk] = true;
                    bfs.push({ni, nj, nk});
                }
            }
            ++steps;
        }

        return -1;
    }
};