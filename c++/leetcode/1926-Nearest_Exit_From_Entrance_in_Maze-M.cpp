class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int m = maze.size(), n = maze[0].size();

        queue<pair<int,int>> bfs;
        bfs.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = 'x';

        int delta[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int steps = 0;
        while (!bfs.empty()) {
            int search_size = bfs.size();
            ++steps;
            for (int k = 0; k < search_size; ++k) {
                auto [i, j] = bfs.front();
                bfs.pop();                
                for (auto [di, dj] : delta) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || maze[ni][nj] != '.') continue;
                    if (ni == 0 || ni == m - 1 || nj == 0 || nj == n - 1) return steps;
                    maze[ni][nj] = 'x';
                    bfs.push({ni, nj});
                }
            }
        }

        return -1;
    }
};
