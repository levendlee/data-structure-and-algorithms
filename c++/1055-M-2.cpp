class Solution {
public:
    int shortestWay(string source, string target) {
        /*
        const int m = source.size();
        const int n = target.size();

        int cnt0[26] = {0};
        int cnt1[26] = {0};
        for (auto c : source) cnt0[c - 'a']++;
        for (auto c : target) cnt1[c - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] > 0 && cnt0[i] == 0) return -1;
        }

        int subseq = 0;
        int i = 0, j = 0;
        auto increase_i = [&] {
            ++i;
            if (i == m) {
                ++subseq;
                i = 0;
            }
        };
        while (j < n) {
            while (source[i] != target[j]) increase_i();
            ++j;
            if (j < n) increase_i();
        }
        return subseq + 1;
        */
        const int m = source.size();
        const int n = target.size();
        if (m == 0 || n == 0) return -1;

        vector<vector<int>> next_char(m, vector<int>(26, -1));
        vector<int> last_char(26, -1);

        for (int i = m - 1; i >= 0; --i) {
            next_char[i] = last_char;
            last_char[source[i] - 'a'] = i;
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int k = 0; k < 26; ++k) {
                if (next_char[i][k] == -1) {
                    next_char[i][k] = last_char[k];
                }
            }
        }

        int subseq = 1;
        int idx = last_char[target[0] - 'a'];
        for (int i = 1; i < n; ++i) {
            auto next_idx = next_char[idx][target[i] - 'a'];
            if (next_idx <= idx) ++subseq;
            idx = next_idx;
            if (idx == -1) return -1;
        }
        return subseq;
    }
};