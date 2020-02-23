class Solution {
public:
    string minWindow(string s, string t) {
        const int n1 = s.size();
        const int n2 = t.size();

        int cnt[256] = {0};
        int tmp[256] = {0};
        for (auto c : t) ++cnt[c];

        string res;
        int covered = 0;
        int i = 0, j = 0;
        while (j < n1) {
            if (++tmp[s[j]] <= cnt[s[j]]) covered++;
            if (covered == n2) {
                while (tmp[s[i]] > cnt[s[i]]) tmp[s[i++]]--;
                if (res.empty() || res.size() > (j - i + 1)) {
                    res = s.substr(i, j - i + 1);
                }
            }
            ++j;
        }
        return res;
    }
};