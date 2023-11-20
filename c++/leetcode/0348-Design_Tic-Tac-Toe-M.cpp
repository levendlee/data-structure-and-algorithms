// 348 Design Tic-Tac-Toe
// https://leetcode.com/problems/design-tic-tac-toe

// version: 1; create time: 2019-12-30 11:34:15;
class TicTacToe {
private:
    int n_;
    vector<vector<int>> board_;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n_(n), board_(n, vector<int>(n, 0)) {

    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board_[row][col] = player;
        /*
        bool wins = true;
        for (int i = 0; i < n_; ++i) {
            if (board_[row][i] != player) {
                wins = false;
                break;
            }
        }
        if (wins) return player;

        wins = true;
        for (int i = 0; i < n_; ++i) {
            if (board_[i][col] != player) {
                wins = false;
                break;
            }
        }
        if (wins) return player;

        if (row == col) {
            wins = true;
            for (int i = 0; i < n_; ++i) {
                if (board_[i][i] != player) {
                    wins = false;
                    break;
                }
            }
            if (wins) return player;
        }

        if (n_ - 1 - row == col) {
            wins = true;
            for (int i = 0; i < n_; ++i) {
                if (board_[n_ - 1 - i][i] != player) {
                    wins = false;
                    break;
                }
            }
            if (wins) return player;
        }
        return 0;
        */
        bool wins[4] = {true, true, true, true};
        for (int i = 0; i < n_; ++i) {
            wins[0] &= board_[row][i] == player;
            wins[1] &= board_[i][col] == player;
            wins[2] &= board_[i][i] == player;
            wins[3] &= board_[n_-1-i][i] == player;
        }
        return (wins[0] || wins[1] || wins[2] || wins[3]) ? player : 0;
    }
};

//

class TicTacToe {
public:
    TicTacToe(int n) {
        n_ = n;
        board_ = vector<vector<int>>(n, vector<int>(n, 0));
        row_sums_ = vector<vector<int>>(2, vector<int>(n, 0));
        col_sums_ = vector<vector<int>>(2, vector<int>(n, 0));
        diag_sums_ = vector<vector<int>>(2, vector<int>(2, 0));
    }

    int move(int row, int col, int player) {
        board_[row][col] = player;
        if (++row_sums_[player - 1][row] == n_ ||
            ++col_sums_[player - 1][col] == n_ ||
            row == col && ++diag_sums_[player - 1][0] == n_ ||
            row + col == n_ - 1 && ++diag_sums_[player - 1][1] == n_) {
            return player;
        }
        return 0;
    }

private:
    int n_;
    vector<vector<int>> board_;
    vector<vector<int>> row_sums_;
    vector<vector<int>> col_sums_;
    vector<vector<int>> diag_sums_;
};
