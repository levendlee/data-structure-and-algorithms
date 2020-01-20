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