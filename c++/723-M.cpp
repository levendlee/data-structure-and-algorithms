class Solution {
private:
    bool crush(vector<vector<int>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        bool crushed = false;
        for (int i = 0; i < m; ++i) {
            int k = 0;
            for (int j = 0; j < n; ++j) {
                if ((j == n - 1) || (abs(board[i][j]) != abs(board[i][j+1]))) {
                    if (j - k >= 2) {
                        crushed |= board[i][k] != 0;
                        for (int t = k; t <= j; ++t) {
                            board[i][t] = -abs(board[i][t]);
                        }
                    }
                    k = j + 1;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            int k = 0;
            for (int i = 0; i < m; ++i) {
                if ((i == m - 1) || (abs(board[i][j]) != abs(board[i+1][j]))) {
                    if (i - k >= 2) {
                        crushed |= board[k][j] != 0;
                        for (int t = k; t <= i; ++t) {
                            board[t][j] = -abs(board[t][j]);
                        }
                    }
                    k = i + 1;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            int src = m - 1;
            int dst = m - 1;
            while (src >= 0) {
                if (board[src][j] > 0) {
                    board[dst][j] = board[src][j];
                    --dst; --src;
                } else {
                    --src;
                }
            }

            while (dst >= 0) {
                board[dst][j] = 0;
                --dst;
            }
        }
        return crushed;
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (crush(board));
        return board;
    }
};