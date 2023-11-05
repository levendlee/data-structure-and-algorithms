class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r_cnt[26] = {0};
        int m_cnt[26] = {0};

        for (char c : ransomNote) {
            ++r_cnt[c - 'a'];
        }
        for (char c : magazine) {
            ++m_cnt[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (r_cnt[i] > m_cnt[i]) return false;
        }

        return true;
    }
};
