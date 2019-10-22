class Solution {
private:
    class TireNode {
        private:
            TireNode* children[26]{};

        public:
            string str;

            TireNode*& getChild(char c) {
                return children[c - 'a'];
            }

            TireNode*& getChild(int i) {
                return children[i];
            }

            template <typename T>
            TireNode* getOrAddChild(T idx) {
                if (!getChild(idx)) {
                    getChild(idx) = new TireNode();
                }
                return getChild(idx);
            }
    };

    TireNode* root_;
    vector<vector<string>> res_;

public:
    void getAllStrings(TireNode* node, vector<string>& strs) {
        if (!node) return;
        if (!node->str.empty()) strs.push_back(node->str);

        for (int i = 0; i < 26; ++i) {
            getAllStrings(node->getChild(i), strs);
        }
    }

    void dfs(vector<string>& cur_vec) {
        if (!cur_vec.empty() && (cur_vec.size() == cur_vec[0].size())) {
            res_.push_back(cur_vec);
            return;
        }

        const int idx = cur_vec.size();
        TireNode* node = root_;
        for (int i = 0; i < idx; ++i) {
            node = node->getChild(cur_vec[i][idx]);
            if (!node) return;
        }

        for (int i = 0; i < 26; ++i) {
            vector<string> strs;
            getAllStrings(node->getChild(i), strs);
            for (auto& s: strs) {
                cur_vec.push_back(s);
                dfs(cur_vec);
                cur_vec.pop_back();
            }
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        root_ = new TireNode();

        for (const auto& w: words) {
            auto node = root_;
            for(const auto& c: w) {
                node = node->getOrAddChild(c);
            }
            node->str = w;
        }

        vector<string> cur_vec;
        dfs(cur_vec);

        return res_;
    }
};