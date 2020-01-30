class Solution {
public:
    bool checkPattern(const string& w, const string& p) {
        const int n = p.size();
        if (w.size() != n) return false;

        char trans1[26];
        char trans2[26];
        std::fill(trans1, trans1 + 26, '#');
        std::fill(trans2, trans2 + 26, '#');
        for (int i = 0; i < n; ++i) {
            const int idx1 = w[i] - 'a';
            const int idx2 = p[i] - 'a';
            if (trans1[idx1] != '#' && trans1[idx1] != p[i]) return false;
            if (trans2[idx2] != '#' && trans2[idx2] != w[i]) return false;
            trans1[idx1] = p[i];
            trans2[idx2] = w[i];
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        const int n = pattern.size();
        for (const auto& w : words) {
            if (checkPattern(w, pattern)) {
                res.push_back(w);
            }
        }
        return res;
    }
};