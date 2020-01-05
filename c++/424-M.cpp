class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26];
        std::fill(count, count + 26, 0);

        const int n = s.size();
        if (n == 0) return 0;

        int i = 0, j = 0;
        int len = 0;
        while (j < n) {
            ++count[s[j] - 'A'];
            while ((j - i + 1) - *std::max_element(count, count + 26) > k) {
                --count[s[i++] - 'A'];
            };
            len = std::max(len, j - i + 1);
            ++j;
        }

        return len;
    }
};