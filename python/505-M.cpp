class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        const int m = maze.size();
        if (m == 0) return -1;
        const int n = maze[0].size();
        if (n == 0) return -1;

        if (start == dest) return 0;

        vector<vector<char>> visit(m, vector<char>(n, 0));
        deque<vector<int>> bfs;
        for (int k = 0; k < 4; ++k) {
            visit[start[0]][start[1]] |= 1 << k;
            bfs.push_back({start[0], start[1], k});
        }

        int dist = 0;
        while (!bfs.empty()) {
            int size = bfs.size();
            for (int i = 0; i < size; ++i) {
                auto loc = bfs.front(); bfs.pop_front();
                auto k = loc[2];
                auto x = k == 0 ? loc[0] + 1 :
                         k == 1 ? loc[0] - 1 : loc[0];
                auto y = k == 2 ? loc[1] + 1 :
                         k == 3 ? loc[1] - 1 : loc[1];
                if (x < 0 || x >= m || y < 0 || y >= n || maze[x][y]) {
                    auto x = loc[0], y = loc[1];
                    if (x == dest[0] && y == dest[1]) return dist;
                    for (int k = 0; k < 4; ++k) {
                        if (visit[x][y] & (1 << k)) continue;
                        visit[x][y] |= 1 << k;
                        ++size;
                        bfs.push_front({x, y, k});
                    }
                } else {
                    if (visit[x][y] & (1 << k)) continue;
                    visit[x][y] |= 1 << k;
                    bfs.push_back({x, y, k});
                }
            }
            ++dist;
        }

        return -1;
    }
};