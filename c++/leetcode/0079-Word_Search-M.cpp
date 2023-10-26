// 79 Word Search
// https://leetcode.com/problems/word-search

// version: 1; create time: 2020-02-01 22:32:00;
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, const string& word, int idx) {
        constexpr int offsets[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        if (idx == word.size())
            return true;
        for (int k = 0; k < 4; ++k) {
            const int ni = i + offsets[k][0];
            const int nj = j + offsets[k][1];
            if (ni < 0 || ni >= board.size() || nj < 0 || nj >= board[0].size() || word[idx] != board[ni][nj]) continue;
            char tmp = '#'; std::swap(tmp, board[ni][nj]);
            if (dfs(board, ni, nj, word, idx + 1))
                return true;
            std::swap(tmp, board[ni][nj]);
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != word[0]) continue;
                board[i][j] = '#';
                if (dfs(board, i, j, word, 1))
                    return true;
                board[i][j] = word[0];
            }
        }
        return false;
    }
};

// 2023/10/23
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();

        function<bool(int, int, int)> dfs;
        dfs = [&](int match, int i, int j) {
            if (match == word.size()) return true;
            if (i < 0 || i >= m || j < 0 || j >= n) return false;
            if (board[i][j] != word[match]) return false;

            char temp = '#';
            swap(board[i][j], temp);
            if (dfs(match + 1, i + 1, j) ||
                dfs(match + 1, i - 1, j) ||
                dfs(match + 1, i, j + 1) ||
                dfs(match + 1, i, j - 1)) {
                return true;
            }
            swap(board[i][j], temp);

            return false;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
