// 242 Valid Anagram
// https://leetcode.com/problems/valid-anagram

// version: 1; create time: 2020-02-01 22:56:11;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int cnt[26] = {0};
        for (const auto& c : s) {
            ++cnt[c - 'a'];
        }
        for (const auto& c : t) {
            if (--cnt[c - 'a'] < 0) return false;
        }
        return true;
    }
};
