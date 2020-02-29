// 472 Concatenated Words
// https://leetcode.com/problems/concatenated-words

// version: 1; create time: 2019-12-30 11:34:15;
// Trie
struct TrieNode {
    string* str;
    TrieNode* next[26];

    TrieNode() : str(nullptr) {
        std::fill(next, next + 26, nullptr);
    }

    TrieNode* getNext(char c) {
        size_t idx = c - 'a';
        if (next[idx] == nullptr) {
            next[idx] = new TrieNode();
        }
        return next[idx];
    }

    bool hasNext(char c) {
        size_t idx = c - 'a';
        return next[idx] != nullptr;
    }
};

class Solution {
private:
    TrieNode* root_;

public:

    bool searchConcat(TrieNode* node, const string& str, int idx) {
        const int n = str.size();
        if (idx >= n) {
            return true;
        }
        while (idx < n) {
            const char c = str[idx];
            if (node->hasNext(c)) {
                node = node->getNext(c);
            } else {
                return false;
            }
            ++idx;
            if (node->str && *(node->str) != str && searchConcat(root_, str, idx)) {
                return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        std::sort(words.begin(), words.end(),
                 [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });

        root_ = new TrieNode();
        vector<string> res;
        for (auto& str : words) {
            if (str.empty()) continue;
            if (searchConcat(root_, str, 0)) {
                res.push_back(str);
            } else {
                TrieNode* node = root_;
                for (const auto c : str) {
                    node = node->getNext(c);
                }
                node->str = &str;
            }
        }
        return res;
    }
};
