// 208 Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree

// version: 1; create time: 2019-11-06 21:47:19;
class Trie {
private:
    struct Node {
        Node* children[26];
        bool exist;

        Node() : exist(false) {
            for (size_t i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    Node* root_;

public:
    /** Initialize your data structure here. */
    Trie() : root_(new Node()) {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = root_;
        for (const auto& c : word) {
            if (!node->children[c-'a']) {
                node->children[c-'a'] = new Node();
            }
            node = node->children[c-'a'];
        }
        node->exist = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = root_;
        for (const auto& c : word) {
            if (!node->children[c-'a']) {
                return false;
            }
            node = node->children[c-'a'];
        }
        return node->exist;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = root_;
        for (const auto& c : prefix) {
            if (!node->children[c-'a']) {
                return false;
            }
            node = node->children[c-'a'];
        }
        return true;
    }
};

// 2923/10/23

class Trie {
public:
    Trie() {
        root_ = new Node();
    }

    void insert(string word) {
        Node* node = root_;
        for (char c : word) {
            node = node->GetOrCreateChild(c);
        }
        node->has_word = true;
    }

    bool search(string word) {
        Node* node = root_;
        for (char c : word) {
            node = node->children[c - 'a'];
            if (!node) {
                return false;
            }
        }
        return node->has_word;
    }

    bool startsWith(string prefix) {
        Node* node = root_;
        for (char c : prefix) {
            node = node->children[c - 'a'];
            if (!node) {
                return false;
            }
        }
        return true;
    }

private:
    struct Node {
        bool has_word;
        Node* children[26];

        Node() : has_word(false) {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }

        Node* GetOrCreateChild(char c) {
            int idx = c - 'a';
            if (!children[idx]) {
                children[idx] = new Node();
            }
            return children[idx];
        }
    };

    Node* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
