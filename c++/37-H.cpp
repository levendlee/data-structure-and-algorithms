class Solution {
private:
    int m_;
    int n_;

public:
    bool solver(vector<vector<char>>& board, vector<vector<int>>& nodes, int idx) {
        if (idx == nodes.size()) return true;

        char seen[9] = {false};
        const auto row = nodes[idx][0];
        const auto col = nodes[idx][1];
        for (int i = 0; i < m_; ++i) {
            if (board[i][col] != '.') {
                seen[board[i][col] - '1'] = true;
            }
        }
        for (int j = 0; j < n_; ++j) {
            if (board[row][j] != '.') {
                seen[board[row][j] - '1'] = true;
            }
        }
        const auto srow = (row / 3) * 3;
        const auto scol = (col / 3) * 3;
        for (int i = srow; i < srow + 3; ++i) {
            for (int j = scol; j < scol + 3; ++j) {
                if (board[i][j] != '.') {
                    seen[board[i][j] - '1'] = true;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            if (seen[i]) continue;
            board[row][col] = i + '1';
            if (solver(board, nodes, idx + 1)) return true;
        }
        board[row][col] = '.';
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        m_ = board.size(); if (m_ == 0) return;
        n_ = board[0].size(); if (n_ == 0) return;

        vector<vector<int>> empty_nodes;
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (board[i][j] == '.') {
                    empty_nodes.push_back({i, j});
                }
            }
        }

        solver(board, empty_nodes, 0);
    }
};