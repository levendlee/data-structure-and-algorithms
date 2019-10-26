class Solution {
public:
    void dfs(const string& s, int idx, const string& prefix, vector<string>& res) {
        const int n = s.size();

        if (idx == n) {
            res.push_back(prefix);
            return;
        }

        if (s[idx] == '{') {
            vector<char> options;
            while (idx < n) {
                options.push_back(s[++idx]);
                if (s[++idx] == '}') break;
            }
            std::sort(options.begin(), options.end());
            for (auto c: options) {
                dfs(s, idx + 1, prefix + c, res);
            }
        } else {
            dfs(s, idx + 1, prefix + s[idx], res);
        }
    }

    vector<string> expand(string S) {
        const int n = S.size();
        vector<string> res;
        dfs(S, 0, "", res);
        return res;
    }
};