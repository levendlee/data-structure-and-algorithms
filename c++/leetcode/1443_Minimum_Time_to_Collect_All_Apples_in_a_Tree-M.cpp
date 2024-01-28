class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> edge_map;
        for (const auto& e : edges) {
            edge_map[e[0]].push_back(e[1]);
            edge_map[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        function<int(int)> dfs;
        dfs = [&](int node) {
            int time = 0;
            visited[node] = true;
            for (auto c : edge_map[node]) {
                if (visited[c]) continue;
                int t = dfs(c);
                if (t >= 0) time += t + 2;
            }
            visited[node] = false;
            return (time == 0 && !hasApple[node]) ? -1 : time; 
        };
        return max(dfs(0), 0);
    }
};