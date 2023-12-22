struct Trie {
    Trie() : has_value(false) {
        fill(children, children + 26, nullptr);
    }
    bool has_value;
    Trie* children[26];
};

class MagicDictionary {
public:
    MagicDictionary() {
        root_ = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for (const auto& s : dictionary) {
            auto node = root_;
            for (const auto c : s) {
                int i = c - 'a';
                if (!node->children[i]) {
                    node->children[i] = new Trie();
                }
                node = node->children[i];
            }
            node->has_value = true;
        }
    }
    
    bool search(string searchWord) {
        function<bool(Trie*, int, bool)> dfs;
        dfs = [&](Trie* node, int i, bool mutated) {
            // Must mutate. Not optional.
            if (i == searchWord.size()) return node->has_value && mutated;

            char c = searchWord[i];
            int j = c - 'a';
            if (node->children[j]) {
                if (dfs(node->children[j], i + 1, mutated)) return true;
            }
            if (mutated) return false;
            for (int k = 0; k < 26; ++k) {
                if (k == j || !node->children[k]) continue;
                if (dfs(node->children[k], i + 1, true)) return true;
            }
            return false;
        };

        return dfs(root_, 0, false);
    }

private:
    Trie* root_;
};
