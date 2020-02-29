// 130 Surrounded Regions
// https://leetcode.com/problems/surrounded-regions

// version: 1; create time: 2020-02-15 20:11:06;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        if (m == 0) return;
        const int n = board[0].size();
        if (n == 0) return;

        queue<vector<int>> bfs;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = 'T';
                bfs.push({i, 0});
            }
            if (board[i][n-1] == 'O') {
                board[i][n-1] = 'T';
                bfs.push({i, n-1});
            }
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = 'T';
                bfs.push({0, j});
            }
            if (board[m-1][j] == 'O') {
                board[m-1][j] = 'T';
                bfs.push({m-1, j});
            }
        }
        while (!bfs.empty()) {
            auto i = bfs.front()[0];
            auto j = bfs.front()[1];
            bfs.pop();
            constexpr int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for (int k = 0; k < 4; ++k) {
                auto ii = i + offsets[k][0];
                auto jj = j + offsets[k][1];
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || board[ii][jj] != 'O') continue;
                board[ii][jj] = 'T';
                bfs.push({ii, jj});
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
