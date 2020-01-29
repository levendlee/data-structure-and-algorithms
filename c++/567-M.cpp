class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt[26] = {0};
        for (const auto& c : s1) {
            ++cnt[c - 'a'];
        }

        int cur_cnt[26] = {0};
        int match = 0;
        const int m = s1.size();
        const int n = s2.size();
        for (int i = 0; i < n; ++i) {
            const int idx1 = s2[i] - 'a';
            const int inc = ++cur_cnt[idx1];
            if (inc > 0 && inc <= cnt[idx1]) {
                ++match;
            }
            if (match == m) return true;
            if (i < m - 1) continue;

            const int idx2 = s2[i+1-m] - 'a';
            const int dec = --cur_cnt[idx2];
            if ((i >= m - 1) && (dec >= 0 && dec < cnt[idx2])) {
                --match;
            }
        }
        return false;
    }
};