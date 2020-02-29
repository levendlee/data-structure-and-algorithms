// 139 Word Break
// https://leetcode.com/problems/word-break

// version: 1; create time: 2020-01-04 17:02:46;
struct TrieNode {
    bool valid;
    TrieNode* next[26];

    TrieNode() : valid(false) {
        std::fill(next, next + 26, nullptr);
    }
    TrieNode* getNext(char c) {
        int idx = c - 'a';
        if (!next[idx]) {
            next[idx] = new TrieNode();
        }
        return next[idx];
    }
    bool hasNext(char c) {
        return next[c - 'a'];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (const auto& word : wordDict) {
            auto node = root;
            for (const auto c : word) {
                node = node->getNext(c);
            }
            node->valid = true;
        }

        const int n = s.size();
        vector<bool> visited(n, false);
        priority_queue<int> pq;
        pq.push(0);
        while (!pq.empty()) {
            auto idx = pq.top(); pq.pop();
            auto node = root;
            while (idx < n) {
                const char c = s[idx];
                if (!node->hasNext(c)) break;
                node = node->getNext(c);
                ++idx;
                if (node->valid && idx == n) {
                    return true;
                }
                if (idx == n) break;
                if (node->valid && !visited[idx]) {
                    pq.push(idx);
                    visited[idx] = true;
                }
            }
        }

        return false;
    }
};
