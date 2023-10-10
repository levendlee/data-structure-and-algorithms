// 36 Valid Sudoku
// https://leetcode.com/problems/valid-sudoku

// version: 1; create time: 2020-02-01 20:55:37;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            bool cnt[9] = {false};
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (cnt[board[i][j] - '1']) return false;
                cnt[board[i][j] - '1'] = true;
            }
        }
        for (int i = 0; i < 9; ++i) {
            bool cnt[9] = {false};
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;
                if (cnt[board[j][i] - '1']) return false;
                cnt[board[j][i] - '1'] = true;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                bool cnt[9] = {false};
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        if (board[k][l] == '.') continue;
                        if (cnt[board[k][l] - '1']) return false;
                        cnt[board[k][l] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};

// 2023/10/04

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto mark_filled = [](int* marker, char value) {
            if (value != '.') {
                if (marker[value - '1']) {
                    return false;
                }
                marker[value - '1'] = 1;
            }
            return true;
        };

        int row_filled[9];
        int col_filled[9];
        int block_filled[9];
        for (int i = 0; i < 9; ++i) {
            std::fill(row_filled, row_filled + 9, 0);
            std::fill(col_filled, col_filled + 9, 0);
            std::fill(block_filled, block_filled + 9, 0);
            for (int j = 0; j < 9; ++j) {
                if (!mark_filled(row_filled, board[i][j])) {
                    std::cout << "haha\n";
                    return false;
                }
                if (!mark_filled(col_filled, board[j][i])) {
                    std::cout << "lala\n";
                    return false;
                }
                if (!mark_filled(block_filled, board[(i/3)*3 + (j/3)][(i%3)*3 + (j%3)])) {
                    std::cout << "lolo\n";
                    return false;
                }
            }
        }

        return true;
    }
};
