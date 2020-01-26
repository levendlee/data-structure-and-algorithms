class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        const int n = words1.size();
        if (n == 0) return true;

        const auto construct_hash = [](const auto& l, const auto& r) {
            return std::min(l, r) + "#" + std::max(l, r);
        };

        unordered_set<string> similar;
        for (const auto& p : pairs) {
            similar.insert(construct_hash(p[0], p[1]));
        }

        for (int i = 0; i < n; ++i) {
            if (words1[i] != words2[i] && !similar.count(construct_hash(words1[i], words2[i]))) {
                return false;
            }
        }

        return true;
    }
};