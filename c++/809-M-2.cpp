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