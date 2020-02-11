class Solution {
public:
    // Time complexity is O(NlogN) level. But hard to analysis.
    int longestSubstr(string& str, int s, int e, int k) {
        //std::cout << "checking " << str.substr(s, e - s + 1) << "\n";
        if (s > e) return 0;

        int char_cnt[26] = {0};
        for (int i = s; i <= e; ++i) {
            ++char_cnt[str[i] - 'a'];
        }

        int longest = -1;
        int start = s;
        for (int i = s; i <= e; ++i) {
            if (char_cnt[str[i] - 'a'] < k) {
                longest = max(longest, longestSubstr(str, start, i - 1, k));
                start = i + 1;
            }
        }
        return max(longest, start == s ? (e - s + 1) : longestSubstr(str, start, e, k));
    }

    int longestSubstring(string s, int k) {
        if (s.empty()) return 0;
        return longestSubstr(s, 0, s.size() - 1, k);
    }
};