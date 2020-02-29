// 266 Palindrome Permutation
// https://leetcode.com/problems/palindrome-permutation

// version: 1; create time: 2020-02-08 16:59:49;
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[256] = {0};
        for (auto c : s) {
            ++cnt[c];
        }
        int rem = 0;
        for (int i = 0; i < 256; ++i) {
            rem += cnt[i] % 2;
        }
        return rem <= 1;
    }
};
