// 30 Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-of-all-words

// version: 1; create time: 2020-01-30 23:09:36;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int n = s.size();
        const int k = words.size();
        if (k == 0) return {};
        const int m = words[0].size();

        unordered_map<string, int> hashmap;
        unordered_map<string, int> hashcnt;
        int i = 0;
        for (const auto& w : words) {
            hashmap[w] = i++;
            ++hashcnt[w];
        }

        vector<vector<int>> dp(m, vector<int>(k, 0));
        vector<int> cnt(m, 0);
        vector<int> res;
        for (int i = m - 1; i < n; ++i) {
            const auto last_word = s.substr(i - m + 1, m);
            const auto last_index = hashmap.count(last_word) ? hashmap[last_word] : -1;
            if (last_index != -1 && ++dp[i%m][last_index] == hashcnt[last_word]) ++cnt[i%m];
            if (i >= m * (k + 1) - 1) {
                const auto first_word = s.substr(i - m * (k + 1) + 1, m);
                const auto first_index = hashmap.count(first_word) ? hashmap[first_word] : -1;
                if (first_index != -1 && dp[i%m][first_index]-- == hashcnt[first_word]) --cnt[i%m];
            }
            if (cnt[i%m] == hashmap.size()) res.push_back(i - m * k + 1);
        }
        return res;
    }
};
