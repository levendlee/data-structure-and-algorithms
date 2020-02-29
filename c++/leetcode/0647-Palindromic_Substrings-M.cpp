// 647 Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings

// version: 1; create time: 2020-02-01 19:05:41;
class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        if (n == 0) return 0;

        int cnt = n;
        vector<int> even(n, true);
        vector<int> odd(n, true);
        for (int size = 2; size <= n; ++size) {
            for (int i = 0; i + size <= n; ++i) {
                int j = i + size - 1;
                bool is_palindrome = (s[i] == s[j]) && (size & 0x1 ? odd[i+1] : even[i+1]);
                cnt += is_palindrome;
                if (size & 0x1) {
                    odd[i] = is_palindrome;
                } else {
                    even[i] = is_palindrome;
                }
            }
        }
        return cnt;
    }
};
