// 791 Custom Sort String
// https://leetcode.com/problems/custom-sort-string

// version: 1; create time: 2020-02-08 15:42:11;
class Solution {
public:
    string customSortString(string S, string T) {
        int chr_idx[26] = {-1};
        for (int i = 0; i < S.size(); ++i) {
            char c = S[i];
            chr_idx[c - 'a'] = i;
        }
        std::sort(T.begin(), T.end(),
                 [&](const auto& l, const auto& r) {
                     return chr_idx[l - 'a'] < chr_idx[r - 'a'];
                 });
        return T;
    }
};
