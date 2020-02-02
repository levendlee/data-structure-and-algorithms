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