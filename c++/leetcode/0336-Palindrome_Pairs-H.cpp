// 336 Palindrome Pairs
// https://leetcode.com/problems/palindrome-pairs

// version: 1; create time: 2020-01-26 20:23:56;
struct TrieNode {
    vector<unsigned> inorder;
    vector<unsigned> reverse;
    TrieNode* next[26];

    TrieNode() {
        std::fill(next, next + 26, nullptr);
    }
    TrieNode* getNext(char c) {
        const int i = c - 'a';
        if (!next[i]) next[i] = new TrieNode();
        return next[i];
    }
    bool hasNext(char c) {
        const int i = c - 'a';
        return next[i];
    }
};

class Solution {
private:
    static bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int n = words.size();
        unordered_set<unsigned> res;

        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; ++i) {
            auto& w = words[i];
            const int m = w.size();

            auto node = root;
            for (int j = 0; j < m; ++j) {
                node = node->getNext(w[j]);
            }
            node->inorder.push_back(i);

            node = root;
            std::reverse(w.begin(), w.end());
            for (int j = 0; j < m; ++j) {
                node = node->getNext(w[j]);
            }
            std::reverse(w.begin(), w.end());
            node->reverse.push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            auto& w = words[i];
            const int m = w.size();

            auto node = root;
            for (int j = 0; j <= m; ++j) {
                if (isPalindrome(w, j, m - 1)) {
                    for (const auto& next : node->reverse) {
                        if (next != i)
                            res.insert((i << 15) | next);
                    }
                }
                if (j < m)
                    node = node->getNext(w[j]);
            }

            node = root;
            std::reverse(w.begin(), w.end());
            for (int j = 0; j <= m; ++j) {
                if (isPalindrome(w, j, m - 1)) {
                    for (const auto& prev : node->inorder) {
                        if (prev != i)
                            res.insert((prev << 15) | i);
                    }
                }
                if (j < m)
                    node = node->getNext(w[j]);
            }
        }

        vector<vector<int>> res_vec;
        constexpr unsigned mask = ((1 << 15) - 1);
        for (const auto& concat : res) {
            res_vec.push_back({(concat >> 15) & mask, concat & mask});
        }

        return res_vec;
    }
};
