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
