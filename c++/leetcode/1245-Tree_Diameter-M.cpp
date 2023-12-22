class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        if (edges.empty()) return 0;

        unordered_map<int, vector<int>> hashed_edges;
        for (const auto& e : edges) {
            hashed_edges[e[0]].push_back(e[1]);
            hashed_edges[e[1]].push_back(e[0]);
        }
        int root = hashed_edges.begin()->first;
        int diameter = 1;
        function<int(int)> dfs;
        unordered_set<int> visited;
        dfs = [&](int root) {
            int max_depth_0 = 0;
            int max_depth_1 = 0;
            for (const auto& c : hashed_edges[root]) {
                if (visited.count(c)) continue;
                visited.insert(c);
                int depth = dfs(c);
                if (depth >= max_depth_0) {
                    max_depth_1 = max_depth_0;
                    max_depth_0 = depth;
                } else if (depth >= max_depth_1) {
                    max_depth_1 = depth;
                }
            }
            diameter = max(diameter, max_depth_0 + max_depth_1);
            return max(max_depth_0, max_depth_1) + 1;
        };
        visited.insert(root);
        dfs(root);
        return diameter;
    }
};
