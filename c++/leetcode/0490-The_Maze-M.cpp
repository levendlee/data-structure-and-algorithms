// 490 The Maze
// https://leetcode.com/problems/the-maze

// version: 1; create time: 2020-01-19 22:41:23;
class Solution {
private:
    int m_;
    int n_;
    constexpr static int delta[4][2] = {{0,1}, {0,-1}, {1,0},{-1,0}};

public:
    bool dfs(const vector<vector<int>>& maze, vector<vector<short>>& visited,
             int si, int sj, const int di, const int dj, const int d) {
        if (visited[si][sj] & (1 << d)) {
            return false;
        }
        visited[si][sj] |= 1 << d;

        while (si >= 0 && si < m_ && sj >= 0 && sj < n_ && maze[si][sj] == 0) {
            si += delta[d][0]; sj += delta[d][1];
        }
        si -= delta[d][0]; sj -= delta[d][1];
        if (si == di && sj == dj) return true;
        visited[si][sj] |= 1 << d;

        for (int nd = 0; nd < 4; ++nd) {
            if (nd == d) continue;
            if (dfs(maze, visited, si, sj, di, dj, nd)) return true;
        }
        return false;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m_ = maze.size();
        if (m_ == 0) return false;
        n_ = maze[0].size();
        if (n_ == 0) return false;

        vector<vector<short>> visited(m_, vector<short>(n_, 0));
        for (int i = 0; i < 4; ++i) {
            if (dfs(maze, visited, start[0], start[1], destination[0], destination[1], i)) {
                return true;
            }
        }
        return false;
    }
};

//

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        const int m = maze.size(), n = maze[0].size();

        // direction: 1: up; 2: down; 3: left; 4: right.
        constexpr int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto valid_index = [&](int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n;
        };
        auto hit_wall = [&](int i, int j) {
            return !valid_index(i, j) || maze[i][j] & 0x1;
        };

        function<bool(int, int, int)> dfs;
        dfs = [&](int i, int j, int d) {
            if (maze[i][j] & (1 << d)) return false;
            maze[i][j] |= 1 << d;

            int ii = i + offsets[d - 1][0], jj = j + offsets[d - 1][1];
            if (!hit_wall(ii, jj)) {
                // Doesn't hit wall.
                if (dfs(ii, jj, d)) return true;
            } else {
                // Hit wall
                if (i == destination[0] && j == destination[1]) return true;
                for (int dd = 1; dd <= 4; ++dd) {
                    if (dd == d) continue;
                    int ii = i + offsets[dd - 1][0], jj = j + offsets[dd - 1][1];
                    if (!hit_wall(ii, jj)) {
                        if (dfs(ii, jj, dd)) return true;
                    }
                }
            }
            return false;
        };

        for (int d = 1; d <= 4; ++d) {
            if (dfs(start[0], start[1], d)) return true;
        }

        return false;
    }
};
