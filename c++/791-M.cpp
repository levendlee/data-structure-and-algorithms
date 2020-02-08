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