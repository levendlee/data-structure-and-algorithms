class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        for (auto& s : stickers) {
            sort(s.begin(), s.end());
        }
        sort(target.begin(), target.end());

        auto reduce = [&](const string& s, const string& t) -> pair<string, string> {
            const int m = s.size(), n = t.size();
            string s_reduced, t_reduced;
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (s[i] == t[j]) {
                    s_reduced.push_back(s[i]);
                    ++i; ++j;
                } else if (s[i] > t[j]) {
                    t_reduced.push_back(t[j]);
                    ++j;
                } else {
                    ++i;
                }
            }
            if (j != n) {
                t_reduced += t.substr(j, n - j);
            }
            return {s_reduced, t_reduced};
        };

        vector<string> reduced_stickers;
        for (const auto& s : stickers) {
            auto [s_reduced, t_reduced] = reduce(s, target);
            if (!s_reduced.empty()) {
                reduced_stickers.push_back(s_reduced); 
            }
        }
        sort(reduced_stickers.begin(), reduced_stickers.end(),
             [](const auto s0, const auto s1) { return s1.size() > s0.size(); });

        unordered_map<string, int> mem;
        function<void(const string&, int, int)> dfs;
        dfs = [&](const string& cur_target, int cur_idx, int cur_stickers) {
            auto iter = mem.find(cur_target);
            if (iter != mem.end() && iter->second <= cur_stickers) {
                return;
            }
            mem[cur_target] = cur_stickers;
            if (cur_target.empty()) {
                return;
            }

            for (int i = cur_idx; i < reduced_stickers.size(); ++i) {
                const auto& s = reduced_stickers[i];
                auto [s_reduced, t_reduced] = reduce(s, cur_target);
                if (s_reduced.empty()) continue;
                dfs(t_reduced, cur_idx, cur_stickers + 1);
            }
        };
        dfs(target, 0, 0);
        return mem.count("") ? mem[""] : -1;
    }
};
