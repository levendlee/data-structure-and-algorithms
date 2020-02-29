// 767 Reorganize String
// https://leetcode.com/problems/reorganize-string

// version: 1; create time: 2020-01-11 10:51:42;
class Solution {
public:
    string reorganizeString(string S) {
        const int n = S.size();
        int count[26] = {0};
        for (const auto c : S) {
            ++count[c - 'a'];
        }
        auto max_idx = std::max_element(count, count + 26) - count;
        auto max_cnt = count[max_idx];
        if (max_cnt > (n + 1) / 2) {
            return "";
        }

        int rank[26];
        std::iota(rank, rank + 26, 0);
        std::sort(rank, rank + 26,
                 [&](const auto& lhs, const auto& rhs) { return count[lhs] > count[rhs]; });

        string res(n, ' ');
        int i = 0, idx = 0;
        while (idx < 26) {
            while (idx < 26 && count[rank[idx]] == 0) ++idx;
            if (idx >= 26) break;
            res[i] = rank[idx] + 'a';
            --count[rank[idx]];
            i += 2;
            if (i >= n) i = 1;
        }
        return res;
    }
};
