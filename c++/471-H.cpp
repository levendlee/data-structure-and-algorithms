class Solution {
private:
    unordered_map<string, string> abbrs_;

public:
    bool isRep(string& s, int i, int j, const string& rep) {
        const int unit = rep.size();
        for (int l = i + unit; l + unit <= j + 1; l += unit) {
            if (s.substr(l, unit) != rep) return false;
        }
        return true;
    }
    void dfs(string& s, int i, const string& abbr) {
        const int n = s.size();
        const auto prefix = s.substr(0, i);
        if (i != 0 && abbrs_.count(prefix) && abbrs_[prefix].size() <= abbr.size()) {
            return;
        }
        abbrs_[prefix] = abbr;
        if (i == n) {
            return;
        }

        // i..k..j
        for (int j = n - 1; j >= i; --j) {
            int total = j - i + 1;
            for (int k = i; k < j; ++k) {
                int unit = k - i + 1;
                if (total % unit) continue;

                auto rep = s.substr(i, unit);
                if (!isRep(s, i, j, rep)) continue;
                auto rep_comp = Solution().encode(rep);
                auto comp = std::to_string(total / unit) + '[' + rep_comp + ']';
                if (comp.size() < total) {
                    dfs(s, j + 1, abbr + comp);
                    break;
                }
            }
        }
        dfs(s, i + 1, abbr + s[i]);
    }

    string encode(string s) {
        dfs(s, 0, "");
        return abbrs_[s];
    }
};