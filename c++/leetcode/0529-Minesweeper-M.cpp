// 529 Minesweeper
// https://leetcode.com/problems/minesweeper

// version: 1; create time: 2020-02-07 23:00:45;
class Solution {
private:
    int m_;
    int n_;

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'E') return;
        constexpr int offsets[8][2] = {{0,1},{0,-1},{1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1}};
        int cnt = 0;
        vector<vector<int>> visit;
        for (int k = 0; k < 8; ++k) {
            int ii = i + offsets[k][0];
            int jj = j + offsets[k][1];
            if (ii < 0 || ii >= m_ || jj < 0 || jj >= n_) continue;
            cnt += board[ii][jj] == 'M';
            visit.push_back({ii, jj});
        }
        //std::cout << cnt << "\n";
        if (cnt == 0) {
            board[i][j] = 'B';
            for (const auto& v : visit) dfs(board, v[0], v[1]);
        } else {
            board[i][j] = '0' + cnt;
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m_ = board.size();
        if (m_ == 0) return board;
        n_ = board[0].size();
        if (n_ == 0) return board;

        int i = click[0], j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        } else {
            dfs(board, i, j);
            return board;
        }
    }
};

//

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        const int m = board.size(), n = board[0].size();

        function<void(int, int)> dfs;
        dfs = [&](int i, int j) {
            char& cur = board[i][j];
            if (cur == 'M') {
                cur = 'X';
                return;
            }
            if (cur == 'B' || cur == 'X') {
                return;
            }
            cur = 'B';
            int mines = 0;
            for (int k0 = -1; k0 <= 1; ++k0) {
                for (int k1 = -1; k1 <=1; ++k1) {
                    if (k0 == 0 && k1 == 0) continue;
                    int ii = i + k0, jj = j + k1;
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    mines += board[ii][jj] == 'M';
                }
            }
            if (mines) {
                cur = mines + '0';
                return;
            }
            for (int k0 = -1; k0 <= 1; ++k0) {
                for (int k1 = -1; k1 <=1; ++k1) {
                    if (k0 == 0 && k1 == 0) continue;
                    int ii = i + k0, jj = j + k1;
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    dfs(ii, jj);
                }
            }
        };
        dfs(click[0], click[1]);

        return board;
    }
};
