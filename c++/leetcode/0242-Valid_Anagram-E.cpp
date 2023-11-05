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

//

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_cnt[256] = {0};
        int t_cnt[256] = {0};

        for (char c: s) {
            ++s_cnt[c];
        }
        for (char c: t) {
            ++t_cnt[c];
        }

        return equal(begin(s_cnt), end(s_cnt), begin(t_cnt));
    }
};
