class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        int cnt1[26] = {0};
        int cnt2[26] = {0};

        for (char c : word1) ++cnt1[c - 'a'];
        for (char c : word2) ++cnt2[c - 'a'];

        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != 0 ^ cnt2[i] != 0) return false;
        }

        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        return equal(cnt1, cnt1 + 26, cnt2);
    }
};
