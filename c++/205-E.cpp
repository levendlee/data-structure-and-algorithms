class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        size_t s_cnt[256];
        std::fill(s_cnt, s_cnt + 256, 0);

        size_t t_cnt[256];
        std::fill(t_cnt, t_cnt + 256, 0);

        int cases = 0;
        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            char sc = s[i];
            char tc = t[i];
            if (s_cnt[sc] && t_cnt[tc]) {
                if (s_cnt[sc] != t_cnt[tc]) {
                    return false;
                }
            } else if (!s_cnt[sc] && !t_cnt[tc]) {
                s_cnt[sc] = t_cnt[tc] = ++cases;
            } else {
                return false;
            }
        }

        return true;
    }
};