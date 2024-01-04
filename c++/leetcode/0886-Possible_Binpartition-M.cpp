class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> conflicts(n + 1);
        for (const auto& p : dislikes) {
            conflicts[p[0]].push_back(p[1]);
            conflicts[p[1]].push_back(p[0]);
        }

        vector<int> colors(n + 1, -1);
        function<bool(int)> dfs;
        dfs = [&](int node) {
            //cout << node << "\n";
            for (int c : conflicts[node]) {
                //cout << c << "#\n";
                if (colors[c] == -1) {
                    colors[c] = 1 - colors[node];
                    if (dfs(c)) {
                        return true;
                    }
                } else if (colors[c] == colors[node]) {
                    return true;
                }
            }
            return false;
        };

        for (int i = 1; i <= n; ++i) {
            if (colors[i] == -1) {
                colors[i] = 0;
                if (dfs(i)) return false;
            }
        }
        return true;
    }
};
