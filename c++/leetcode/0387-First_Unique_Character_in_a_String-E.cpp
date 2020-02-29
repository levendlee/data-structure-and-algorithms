// 387 First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string

// version: 1; create time: 2020-02-11 19:00:51;
class Solution {
public:
    int firstUniqChar(string s) {
        int cnts[26] = {0};
        for (const auto c : s) {
            ++cnts[c-'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (cnts[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
