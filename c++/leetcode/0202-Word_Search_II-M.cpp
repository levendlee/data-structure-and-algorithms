struct Node {
    const string* word;
    Node* children[26];

    Node() : word(nullptr) {
        fill(children, children + 26, nullptr);
    }

    Node * GetChild(char c) {
        if (c < 'a' || c > 'z') return nullptr;
        return children[c - 'a'];
    }

    Node * GetOrCreateChild(char c) {
        int i = c - 'a';
        if (!children[i]) {
            children[i] = new Node();
        }
        return children[i];
    }
};

struct Trie {
    Node* root;

    Trie() : root(new Node()) {

    }

    void AddWord(const string* word) {
        Node* node = root;
        for (char c : *word) {
            node = node->GetOrCreateChild(c);
        }
        node->word = word;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (const string& w : words) {
            trie.AddWord(&w);
        }

        const int m = board.size();
        const int n = board[0].size();
        unordered_set<string> found_words;

        function<void(Node*, int, int)> dfs;
        dfs = [&](Node* node, int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n) return;
            if (board[i][j] == '#') return;
            node = node->GetChild(board[i][j]);
            if (!node) return;

            char temp = '#';
            swap(board[i][j], temp);

            if (node->word) {
                found_words.insert(*node->word);
            }

            dfs(node, i + 1, j);
            dfs(node, i - 1, j);
            dfs(node, i, j + 1);
            dfs(node, i, j - 1);

            swap(board[i][j], temp);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(trie.root, i, j);
            }
        }

        return vector<string>(found_words.begin(), found_words.end());
    }
};
