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