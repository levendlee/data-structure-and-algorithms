struct TrieNode {
    string str;
    TrieNode* next[26];

    TrieNode() : str() {
        std::fill(next, next + 26, nullptr);
    }

    TrieNode* getNext(char c) {
        int idx = c - 'a';
        if (next[idx] == nullptr) {
            next[idx] = new TrieNode();
        }
        return next[idx];
    }

    bool hasNext(char c) {
        int idx = c - 'a';
        return next[idx] != nullptr;
    }
};

class Solution {
private:
    int m_;
    int n_;
    unordered_set<string> found_;

public:
    void dfs(vector<vector<char>>& board, const int i, const int j,
            TrieNode* node) {
        constexpr int offsets[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        char& c = board[i][j];
        if (!node->hasNext(c)) {
            return;
        }
        node = node->getNext(c);
        if (!node->str.empty()) {
            found_.insert(node->str);
        }
        char tmp = '#';
        std::swap(c, tmp);

        for (int k = 0; k < 4; ++k) {
            const int ii = i + offsets[k][0];
            const int jj = j + offsets[k][1];
            if (ii >=0 && ii < m_ && jj >= 0 && jj < n_ && board[ii][jj] != '#') {
                dfs(board, ii, jj, node);
            }
        }
        std::swap(c, tmp);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m_ = board.size();
        if (m_ == 0) return {};
        n_ = board[0].size();
        if (n_ == 0) return {};

        found_.clear();

        TrieNode* root = new TrieNode();
        for (const auto& w : words) {
            TrieNode* node = root;
            for (const auto& c : w) {
                node = node->getNext(c);
            }
            node->str = w;
        }

        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                dfs(board, i, j, root);
            }
        }
        vector<string> res(found_.begin(), found_.end());
        return res;
    }
};