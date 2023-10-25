// 211 Add and Search Word - Data structure design
// https://leetcode.com/problems/add-and-search-word-data-structure-design

// version: 1; create time: 2020-02-05 20:11:20;
struct TrieNode {
    bool valid;
    TrieNode* next[26];

    TrieNode() : valid(false) {
        std::fill(next, next + 26, nullptr);
    }

    TrieNode* getNext(char c) {
        int idx = c - 'a';
        if (!next[idx]) next[idx] = new TrieNode();
        return next[idx];
    }

    bool hasNext(char c) {
        int idx = c - 'a';
        return next[idx];
    }
};

class WordDictionary {
private:
    TrieNode* root_;

    bool dfs_search(TrieNode* node, string& word, int i) {
        if (i == word.size()) {
            return node->valid;
        }
        if (word[i] == '.') {
            for (int j = 0; j < 26; ++j) {
                if (node->next[j] && dfs_search(node->next[j], word, i + 1)) return true;
            }
        } else {
            if (node->hasNext(word[i]) && dfs_search(node->getNext(word[i]), word, i+1)) return true;
        }
        return false;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() : root_(new TrieNode()) {

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto node = root_;
        for (const auto& c : word) {
            node = node->getNext(c);
        }
        node->valid = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs_search(root_, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 // 2023/10/23

 struct Node {
    bool has_word;
    Node* children[26];

    Node() : has_word(false) {
        std::fill(children, children + 26, nullptr);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root_ = new Node();
    }

    void addWord(string word) {
        Node* node = root_;

        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Node();
            }
            node = node->children[idx];
        }
        node->has_word = true;
    }

    bool search(string word) {
        // bfs
        /*
        queue<Node*> q;
        q.push(root_);

        for (char c : word) {
            int num_paths = q.size();
            if (num_paths == 0) {
                return false;
            }

            for (int p = 0; p < num_paths; ++p) {
                Node* node = q.front();
                q.pop();

                if (c == '.') {
                    for (int i = 0; i < 26; ++i) {
                        if (node->children[i]) {
                            q.push(node->children[i]);
                        }
                    }
                } else {
                    if (node->children[c - 'a']) {
                        q.push(node->children[c - 'a']);
                    }
                }
            }
        }

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->has_word) {
                return true;
            }
        }
        return false;
        */

        function<bool(Node*, int)> dfs;
        dfs = [&](Node* node, int word_idx) {
            if (!node) {
                return false;
            }
            if (word_idx == word.size()) {
                return node->has_word;
            }

            char c = word[word_idx];
            if (c == '.') {
                for (int node_idx = 0; node_idx < 26; ++node_idx) {
                    if (dfs(node->children[node_idx], word_idx + 1)) {
                        return true;
                    }
                }
                return false;
            } else {
                int node_idx = word[word_idx] - 'a';
                return dfs(node->children[node_idx], word_idx + 1);
            }
        };

        return dfs(root_, 0);
    }

private:
    Node* root_;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
