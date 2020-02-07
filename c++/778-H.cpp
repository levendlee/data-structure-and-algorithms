class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0) return -1;
        const int n = grid[0].size();
        if (n == 0) return -1;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        priority_queue<vector<int>> pq; // {time_require, x, y}
        pq.push({-grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto time = -pq.top()[0];
            auto x = pq.top()[1];
            auto y = pq.top()[2];
            pq.pop();
            constexpr int offsets[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            for (int k = 0; k < 4; ++k) {
                int nx = x + offsets[k][0];
                int ny = y + offsets[k][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= m) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                if (nx == m - 1 && ny == n - 1) {
                    return std::max(time, grid[nx][ny]);
                }
                pq.push({-std::max(time, grid[nx][ny]), nx, ny});
            }
        }

        return -1;
    }
};