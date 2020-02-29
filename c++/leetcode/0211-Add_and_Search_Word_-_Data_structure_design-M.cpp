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
