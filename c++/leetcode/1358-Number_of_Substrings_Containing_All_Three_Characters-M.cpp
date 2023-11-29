class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3] = {0};
        int present = 0;

        const int n = s.size();
        int i = 0, j = 0, res = 0;
        while (i < n) {
            while (j < n && present < 3) {
                ++cnt[s[j] - 'a'];
                present += cnt[s[j] - 'a'] == 1;
                ++j;
            }
            if (present == 3) {
                res += n - (j - 1);
            }
            --cnt[s[i] - 'a'];
            present -= cnt[s[i] - 'a'] == 0;
            ++i;
        }

        return res;
    }
};
