struct TrieNode {
    priority_queue<string> pq;
    TrieNode* next[26];

    TrieNode() {
        std::fill(next, next + 26, nullptr);
    }
    TrieNode* getNext(char c) {
        size_t idx = c - 'a';
        if (!next[idx]) {
            next[idx] = new TrieNode();
        }
        return next[idx];
    }
    TrieNode* hasNext(char c) {
        size_t idx = c - 'a';
        return next[idx];
    }
    void add(const string& s) {
        if (pq.size() == 3 && s >= pq.top()) return;
        pq.push(s);
        if (pq.size() > 3) pq.pop();
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* const root = new TrieNode();
        for (const auto& s : products) {
            TrieNode* node = root;
            for (const auto& c : s) {
                node = node->getNext(c);
                node->add(s);
            }
        }

        const int n = searchWord.size();
        vector<vector<string>> res(n);
        TrieNode* node = root;
        for (int i = 0; i < n; ++i) {
            const char c = searchWord[i];
            if (!node->hasNext(c)) break;
            node = node->getNext(c);
            auto& pq = node->pq;
            while (!pq.empty()) {
                res[i].push_back(pq.top());
                pq.pop();
            }
            std::reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
};