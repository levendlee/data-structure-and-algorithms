class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<vector<int>>> edges(2, vector<vector<int>>(n));
        for (const auto& e : red_edges) edges[0][e[0]].push_back(e[1]);
        for (const auto& e : blue_edges) edges[1][e[0]].push_back(e[1]);

        vector<int> dist(n, -1);
        vector<int> colors(n, 0);
        dist[0] = 0;

        queue<vector<int>> bfs;
        bfs.push({0, 0});
        bfs.push({0, 1});
        int cur_dist = 0;
        while (!bfs.empty()) {
            for (int i = bfs.size() - 1; i >= 0; --i) {
                auto node = bfs.front()[0];
                auto color = bfs.front()[1];
                bfs.pop();
                for (const auto next : edges[!color][node]) {
                    if (dist[next] != -1 && (colors[next] & (1 << !color))) continue;
                    if (dist[next] == -1) dist[next] = cur_dist + 1;
                    colors[next] |= (1 << !color);
                    bfs.push({next, !color});
                }
            }
            ++cur_dist;
        }
        return dist;
    }
};