// 424 Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement

// version: 1; create time: 2020-01-05 15:15:20;
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

//

class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();
        int i = 0, j = 0, max_len = 0;
        int count[26] = {0};
        while (j < n) {
            ++count[s[j] - 'A'];
            while ((j - i + 1) - *std::max_element(count, count + 26) > k) {
                --count[s[i++] - 'A'];
            }
            max_len = max(max_len, (j - i + 1));
            ++j;
        }
        return max_len;
    }
};