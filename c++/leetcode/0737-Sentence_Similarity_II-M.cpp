// 737 Sentence Similarity II
// https://leetcode.com/problems/sentence-similarity-ii

// version: 1; create time: 2020-01-18 21:41:15;
class Solution {
private:
    vector<int> p_;

    int find_(int i) {
        if (p_[i] != i) {
            p_[i] = p_[p_[i]];
            return find_(p_[i]);
        } else {
            return i;
        }

    }

    void union_(int i, int j) {
        auto pi = find_(i);
        auto pj = find_(j);
        if (pi != pj) {
            p_[pi] = pj;
        }
    }

public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        const int m = words1.size();
        if (m == 0) return true;

        unordered_map<string, int> id_map;
        auto add_str = [&](const auto& str) {
            if (!id_map.count(str)) {
                auto id = id_map.size();
                id_map[str] = id;
            }
        };

        for (const auto& p : pairs) {
            add_str(p[0]);
            add_str(p[1]);
        }

        const int n = id_map.size();
        p_ = vector<int>(n);
        std::iota(p_.begin(), p_.end(), 0);

        for (const auto& p : pairs) {
            union_(id_map[p[0]], id_map[p[1]]);
        }

        for (int i = 0; i < m; ++i) {
            const auto& w1 = words1[i];
            const auto& w2 = words2[i];
            if (w1 == w2) continue;
            if (!id_map.count(w1) || !id_map.count(w2)) {
                return false;
            }
            if (find_(id_map[w1]) != find_(id_map[w2])) {
                return false;
            }
        }

        return true;
    }
};
