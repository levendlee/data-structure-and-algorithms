// 809 Expressive Words
// https://leetcode.com/problems/expressive-words

// version: 2; create time: 2020-02-17 22:34:07;
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        auto get_char_cnts = [](const string& s) {
            const int n = s.size();
            vector<pair<char, int>> char_cnts;
            int j = 0;
            while (j < n) {
                auto i = j;
                while (j + 1 < n && s[j] == s[j+1]) ++j;
                int cnt = j - i + 1;
                char_cnts.push_back({s[i], cnt});
                ++j;
            }
            return char_cnts;
        };
        
        const auto base = get_char_cnts(S);
        const int n = base.size();
        
        auto is_expressive = [&](const string& word) {
            const auto cur = get_char_cnts(word);
            if (base.size() != cur.size()) return 0;
            for (int i = 0; i < n; ++i) {
                if (base[i].first != cur[i].first) return 0;
                if (base[i].second != cur[i].second && (base[i].second < cur[i].second || base[i].second < 3)) return 0;
            }
            return 1;
        };
        
        int expr_cnt = 0;
        for (const auto& word : words) {
            expr_cnt += is_expressive(word);
        }
        
        return expr_cnt;
    }
};


// version: 1; create time: 2019-10-20 16:12:55;
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        const int n = S.size();

        std::vector<std::pair<char,int>> repeats;
        int repeat_cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || S[i] != S[i+1]) {
                repeats.emplace_back(S[i], repeat_cnt);
                repeat_cnt = 1;
            } else {
                ++repeat_cnt;
            }
        }

        int res = 0;
        for (auto& word: words) {
            const int m = word.size();
            int repeat_cnt = 1;
            int i = 0;
            int k = 0;
            for (;i < m; ++i) {
                if (k >= repeats.size() || word[i] != repeats[k].first) {
                    break;
                }
                if (i == n - 1 || word[i] != word[i+1]) {
                    if (repeats[k].second < 3 && repeat_cnt != repeats[k].second) {
                        break;
                    }
                    if (repeats[k].second >= 3 && repeat_cnt > repeats[k].second) {
                        break;
                    }
                    ++k;
                    repeat_cnt = 1;
                } else {
                    ++repeat_cnt;
                }
            }
            res += (i == m) && (k == repeats.size());
        }

        return res;
    }
};
