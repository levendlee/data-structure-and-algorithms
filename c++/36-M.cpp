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