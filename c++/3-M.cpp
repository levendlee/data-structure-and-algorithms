class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[256];
        std::fill(count, count + 256, 0);

        const int n = s.size();
        int i = 0, j = 0;
        int len = 0;
        while (j < n) {
            ++count[s[j]];
            while (count[s[j]] > 1) {
                --count[s[i++]];
            }
            len = std::max(len, j - i + 1);
            ++j;
        }
        return len;
    }
};