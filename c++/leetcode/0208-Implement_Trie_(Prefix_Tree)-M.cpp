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
