class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> edge_map;
        for (const auto& e : edges) {
            edge_map[e[0]].push_back(e[1]);
            edge_map[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        function<bool(int, int)> detect_cycle;
        detect_cycle = [&](int cur, int prev) {
            if (visited[cur]) return true;
            visited[cur] = true;
            for (int next : edge_map[cur]) {
                if (next == prev) continue;
                if (detect_cycle(next, cur)) {
                    return true;
                }
            }
            return false;
        };
        if (detect_cycle(0, -1)) {
            return false;
        }
        if (accumulate(visited.begin(), visited.end(), 0) != n) {
            return false;
        }

        return true;
    }
};