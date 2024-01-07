// 286 Walls and Gates
// https://leetcode.com/problems/walls-and-gates

// version: 1; create time: 2020-01-30 22:30:56;
struct Node {
    int x;
    int y;
};

class Solution {
public:
    /*
    void dfs(vector<vector<int>>& rooms, int x, int y) {
        constexpr int offsets[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int min_dist = INT_MAX;
        for (int k = 0; k < 4; ++k) {
            const auto nx = x + offsets[k][0];
            const auto ny = y + offsets[k][1];
            if (nx < 0 || nx >= rooms.size() || ny < 0 || ny >= rooms[0].size()) continue;
            if (rooms[nx][ny] == -1) continue;
            dfs(rooms, nx, ny);
            min_dist = std::max(min_dist, rooms[nx][ny] + 1);
        }
    }
    */

    void wallsAndGates(vector<vector<int>>& rooms) {
        const int m = rooms.size();
        if (m == 0) return;
        const int n = rooms[0].size();
        if (n == 0) return;

        queue<Node> bfs;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] != 0) continue;
                bfs.push({i, j});
            }
        }

        int dist = 0;
        while (!bfs.empty()) {
            const int size = bfs.size();
            for (int i = 0; i < size; ++i) {
                const auto node = bfs.front(); bfs.pop();
                constexpr int offsets[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                for (int k = 0; k < 4; ++k) {
                    const auto nx = node.x + offsets[k][0];
                    const auto ny = node.y + offsets[k][1];
                    if (nx < 0 || nx >= rooms.size() || ny < 0 || ny >= rooms[0].size()) continue;
                    if (rooms[nx][ny] <= dist) continue;
                    rooms[nx][ny] = dist + 1;
                    bfs.push({nx, ny});
                }
            }
            ++dist;
        }
    }
};

//

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int m = rooms.size(), n = rooms[0].size();

        // DFS: TLE
        // T: O(N^4).
        // S: O(N^2).
        /*
        function<void(int, int, int)> dfs;
        dfs = [&](int i, int j, int d) {
            rooms[i][j] = d;
            constexpr int offsets[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (int k = 0; k < 4; ++k) {
                int ii = i + offsets[k][0];
                int jj = j + offsets[k][1];
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || rooms[ii][jj] <= d) continue;
                dfs(ii, jj, d + 1);
            }
            return;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    dfs(i, j, 0);
                }
            }
        }
        */

        queue<vector<int>> bfs;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    bfs.push({i, j});
                }
            }
        }

        int steps = 0;
        while (!bfs.empty()) {
            ++steps;
            int search_space = bfs.size();
            for (int i = 0; i < search_space; ++i) {
                auto xy = bfs.front();
                bfs.pop();
                constexpr int offsets[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (int k = 0; k < 4; ++k) {
                    int ii = xy[0] + offsets[k][0];
                    int jj = xy[1] + offsets[k][1];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n || rooms[ii][jj] <= steps) continue;
                    rooms[ii][jj] = steps;
                    bfs.push({ii, jj});
                }
            }
        }
    }
};