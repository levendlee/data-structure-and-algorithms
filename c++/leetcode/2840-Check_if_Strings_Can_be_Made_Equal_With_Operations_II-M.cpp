class Solution {
public:
    bool checkStrings(string s1, string s2) {
        auto get_alpha_counts = [](const string& s) {
            std::vector<int> odd_cnt(26), even_cnt(26);
            for (int i = 0; i < s.size(); ++i) {
                if (i % 2) {
                    ++odd_cnt[s[i] - 'a'];
                } else {
                    ++even_cnt[s[i] - 'a'];
                }
            }
            return std::make_pair(odd_cnt, even_cnt);
        };
        auto cnts1 = get_alpha_counts(s1);
        auto cnts2 = get_alpha_counts(s2);
        return cnts1 == cnts2;
    }
};
