// 720 Longest Word in Dictionary
// https://leetcode.com/problems/longest-word-in-dictionary

// version: 1; create time: 2020-01-26 14:57:16;
class Solution {
public:
    // forward looking is slow.
    // backward looking is faster.
    string longestWord(vector<string>& words) {
        const int n = words.size();
        if (n == 0) return "";

        /*
        std::sort(words.begin(), words.end(),
                  [](const auto& l, const auto& r) { return l.size() < r.size() || (l.size() == r.size()) && (l < r); });

        unordered_map<string, int> index;
        for (int i = 0; i < n; ++i) {
            index[words[i]] = i;
        }

        vector<int> dp(n, false);
        int res_idx = 0, res_len = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] |= words[i].size() == 1;
            if (!dp[i]) continue;
            for (int j = 0; j < 26; ++j) {
                const char c = j + 'a';
                const auto tmp = words[i] + c;
                dp[index[tmp]] = index.count(tmp);
            }
            if (words[i].size() > res_len) {
                res_idx = i;
                res_len = words[i].size();
            }
        }
        return words[res_idx];
        */

        std::sort(words.begin(), words.end());
        unordered_set<string> can_built;
        string res_str;
        for (const auto& s : words) {
            if (s.size() == 1 || can_built.count(s.substr(0, s.size() - 1))) {
                can_built.insert(s);
                if ((s.size() > res_str.size()) || (s.size() == res_str.size()) && (s < res_str)) {
                    res_str = s;
                }
            }
        }
        return res_str;
    }
};
