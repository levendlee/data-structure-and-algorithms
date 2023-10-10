// 3 Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters

// version: 1; create time: 2020-01-05 11:03:17;
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

// 2023/10/03

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        vector<bool> char_set(256, false);
        int i = 0, j = 0;
        int max_len = 0;
        while (j < n) {
            while (char_set[s[j]]) {
                char_set[s[i]] = false;
                ++i;
            };
            char_set[s[j]] = true;
            max_len = std::max(max_len, j - i + 1);
            ++j;
        }
        return max_len;
    }
};
