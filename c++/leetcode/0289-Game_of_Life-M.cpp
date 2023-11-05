// 289 Game of Life
// https://leetcode.com/problems/game-of-life

// version: 1; create time: 2020-02-01 17:28:25;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int m = board.size();
        if (m == 0) return;
        const int n = board[0].size();
        if (n == 0) return;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                constexpr int offsets[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
                for (int k = 0; k < 8; ++k) {
                    const int ni = i + offsets[k][0];
                    const int nj = j + offsets[k][1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    cnt += board[ni][nj] & 0x1;
                }
                if (board[i][j]) {
                    if (cnt == 2 || cnt == 3) {
                        board[i][j] |= 0x2;
                    }
                } else {
                    if (cnt == 3) {
                        board[i][j] |= 0x2;
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};

// 2013/11/05

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbors = 0;
                for (int ii = max(i - 1, 0); ii <= min(i + 1, m - 1); ++ii) {
                    for (int jj = max(j - 1, 0); jj <= min(j + 1, n - 1); ++jj) {
                        if (ii == i && jj == j) continue;
                        if (board[ii][jj] & 0x1) ++neighbors;
                    }
                }
                if (board[i][j] & 0x1) {
                    // live
                    if (neighbors == 2 || neighbors == 3) {
                        board[i][j] |= 1 << 1;
                    }
                } else {
                    // die
                    if (neighbors == 3) {
                        board[i][j] |= 1 << 1;
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};


