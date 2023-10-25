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

// 2023/10/21
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        std::vector<int> uf(m * n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                uf[i * n + j] = i * n + j;
            }
        }

        std::function<int(int)> find_f;
        find_f = [&](int a) {
            if (uf[a] == a) return a;
            return uf[a] = find_f(uf[uf[a]]);
        };

        std::function<int(int, int)> union_f;
        union_f = [&](int a, int b) {
            int pa = find_f(a);
            int pb = find_f(b);
            return uf[pa] = pb;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') continue;
                if (i + 1 < m && board[i + 1][j] == 'O') union_f((i + 1) * n + j, i * n + j);
                if (i - 1 >= 0 && board[i - 1][j] == 'O') union_f((i - 1) * n + j, i * n + j);
                if (j + 1 < n && board[i][j + 1] == 'O') union_f(i * n + j, i * n + j + 1);
                if (j - 1 >= 0 && board[i][j - 1] == 'O') union_f(i * n + j, i * n + j - 1);
            }
        }

        std::unordered_set<int> cannot_flip_sets;
        for (int i = 0; i < m; ++i) {
            cannot_flip_sets.insert(find_f(i * n + 0));
            cannot_flip_sets.insert(find_f(i * n + n - 1));
        }
        for (int j = 0; j < n; ++j) {
            cannot_flip_sets.insert(find_f(0 * n + j));
            cannot_flip_sets.insert(find_f((m-1) * n + j));
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !cannot_flip_sets.count(find_f(i * n + j))) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
