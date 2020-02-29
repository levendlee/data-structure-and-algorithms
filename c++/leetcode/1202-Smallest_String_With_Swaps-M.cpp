// 1202 Smallest String With Swaps
// https://leetcode.com/problems/smallest-string-with-swaps

// version: 1; create time: 2020-01-18 11:00:12;
class Solution {
private:
    std::vector<int> p_;
    std::unordered_map<int, std::vector<int>> connected_;

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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int n = s.size();

        p_ = vector<int>(n, 0);
        std::iota(p_.begin(), p_.end(), 0);

        for (const auto& p : pairs) {
            union_(p[0], p[1]);
        }

        for (int i = 0; i < n; ++i) {
            connected_[find_(i)].push_back(i);
        }

        for (const auto& p : connected_) {
            if (p.second.size() <= 1) continue;
            string tmp;
            for (const auto& i : p.second) {
                tmp += s[i];
            }
            std::sort(tmp.begin(), tmp.end());
            int k = 0;
            for (const auto& i : p.second) {
                s[i] = tmp[k++];
            }
        }

        return s;
    }
};
