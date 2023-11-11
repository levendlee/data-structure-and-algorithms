// V, E
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        unordered_map<int, vector<int>> edges_map;
        for (const auto& e : edges) {
            edges_map[e[0]].push_back(e[1]);
            edges_map[e[1]].push_back(e[0]);
        }

        const int n = values.size();
        vector<bool> visited(n, false);
        function<long long(int)> dfs;
        dfs = [&](int node) {
            if (visited[node]) {
                return 0LL;
            }
            visited[node] = true;
            long long v = values[node];
            long long min_removed = 0;
            for (auto child : edges_map[node]) {
                min_removed += dfs(child);
            }
            visited[node] = false;
            return min_removed == 0 ? v : min(min_removed, v);
        };

        long long total = accumulate(values.begin(), values.end(), 0LL);
        return total - dfs(0);
    }
};
