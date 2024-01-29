// 140 Word Break II
// https://leetcode.com/problems/word-break-ii

// version: 1; create time: 2020-01-11 17:27:38;
struct TrieNode {
    bool valid;
    TrieNode* next[26];

    TrieNode() : valid(false) {
        std::fill(next, next + 26, nullptr);
    }
    TrieNode* getNext(const char c) {
        const int i = c - 'a';
        if (!next[i]) {
            next[i] = new TrieNode();
        }
        return next[i];
    }
    bool hasNext(const char c) {
        const int i = c - 'a';
        return next[i];
    }
};

class Solution {
private:
    TrieNode* root_;
    vector<bool> feasible_;

public:
    void dfs(const string& s, int idx, const string& res, vector<string>& res_vec) {
        const int n = s.size();
        const int start = idx;

        if (!feasible_[start]) return;

        auto node = root_;

        const int init_num_res = res_vec.size();
        while (idx < n) {
            const auto c = s[idx];
            if (!node->hasNext(c)) {
                break;
            }
            node = node->getNext(c);
            if (node->valid) {
                auto tmp = res;
                if (!tmp.empty()) tmp += ' ';
                tmp += s.substr(start, idx - start + 1);
                if (idx + 1 == n) {
                    res_vec.push_back(tmp);
                } else {
                    dfs(s, idx + 1, tmp, res_vec);
                }
            }
            ++idx;
        }

        if (res_vec.size() == init_num_res) {
            feasible_[start] = false;
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode(); root_ = root;
        for (const auto& word : wordDict) {
            auto node = root;
            for (const auto& c : word) {
                node = node->getNext(c);
            }
            node->valid = true;
        }

        const int n = s.size();
        feasible_ = vector<bool>(n, true);

        vector<string> res_vec;
        string res;
        dfs(s, 0, res, res_vec);
        return res_vec;
    }
};
//

class Solution {
public:
    struct TrieNode {
        string s;
        TrieNode* children[26];
    };

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();

        for (const auto& w : wordDict) {
            auto cur = root;
            for (char c : w) {
                auto& next = cur->children[c - 'a'];
                if (!next) {
                    next = new TrieNode();
                }
                cur = next;
            }
            cur->s = w;
        }

        vector<string> results;
        const int n = s.size();
        function<void(int, TrieNode*, string&)> backtracking;
        backtracking = [&](int i, TrieNode* node, string& sentence) {
            if (i == n) {
                if (node == root) {
                    results.push_back(sentence.substr(0, sentence.size() - 1));
                }
                return;
            }

            auto next = node->children[s[i] - 'a'];
            if (!next) return;

            sentence.push_back(s[i]);
            if (!next->s.empty()) {
                sentence.push_back(' ');
                backtracking(i + 1, root, sentence);
                sentence.pop_back();
            }
            backtracking(i + 1, next, sentence);
            sentence.pop_back();
        };

        string sentence;
        backtracking(0, root, sentence);
        return results;
    }
};
