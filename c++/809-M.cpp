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