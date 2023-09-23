class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        constexpr int num_alpha = 26;
        const int num_words = words.size();
    
        vector<int> total_letters_cnt(num_alpha);
        vector<int> word_scores(num_words);
        vector<vector<int>> word_letters_cnt(num_words, vector<int>(num_alpha));

        for (const char c : letters) {
            total_letters_cnt[c - 'a'] += 1;
        }
        for (int i = 0; i < num_words; ++i) {
            for (const char c : words[i]) {
                word_scores[i] += score[c - 'a'];
                ++word_letters_cnt[i][c - 'a'];
            }
        }
        
        auto vfunc = [](function<void(int&, int)> op, vector<int>& lhs, const vector<int>& rhs) {
            for (int i = 0; i < lhs.size(); ++i) {
                op(lhs[i], rhs[i]);
            }
        };
        auto vadd = bind(vfunc, [](int& a, int b) { a += b; }, placeholders::_1, placeholders::_2);
        auto vsub = bind(vfunc, [](int& a, int b) { a -= b; }, placeholders::_1, placeholders::_2);

        int cur_total_score = 0;
        int max_total_score = 0;
        int usused_letter_cnt = letters.size();

        std::function<void(int)> dfs;
        dfs = [&](int start_idx) {
            max_total_score = max(max_total_score, cur_total_score);
            if (start_idx == num_words || usused_letter_cnt == 0) {
                return;
            }

            for (int i = start_idx; i < num_words; ++i) {
                int mask = 1 << i;

                vsub(total_letters_cnt, word_letters_cnt[i]);
                if (std::all_of(total_letters_cnt.begin(), total_letters_cnt.end(), [](int i) { return i >= 0; })) {
                    usused_letter_cnt -= words[i].size();
                    cur_total_score += word_scores[i];

                    dfs(i + 1);

                    usused_letter_cnt += words[i].size();
                    cur_total_score -= word_scores[i];
                }
                vadd(total_letters_cnt, word_letters_cnt[i]);
            }
        };

        dfs(0);
        return max_total_score;
    }
};
