class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        if (s.empty()) return 0;

        unordered_map<int, vector<int>> parent2children;
        for (int i = 0; i < parent.size(); ++i) {
            parent2children[parent[i]].push_back(i);
        }

        int longest_path = 0;
        function<int(int)> dfs;
        dfs = [&](int node) -> int {
            auto iter = parent2children.find(node);

            if (iter != parent2children.end()) {
                int longest_subpath_0 = 0;
                int longest_subpath_1 = 0;
                for (const int child : iter->second) {
                    int subpath = dfs(child);
                    longest_path = max(longest_path, subpath);
                    if (node >= 0 && s[node] == s[child]) continue;
                    if (longest_subpath_0 <= subpath) {
                        longest_subpath_1 = longest_subpath_0;
                        longest_subpath_0 = subpath;
                    } else if (longest_subpath_1 <= subpath) {
                        longest_subpath_1 = subpath;
                    }
                }
                longest_path = max(longest_path, longest_subpath_0 + longest_subpath_1 + (node >= 0));
                return longest_subpath_0 + 1;
            }
            return 1;
        };
        dfs(-1);

        return longest_path;
    }
};