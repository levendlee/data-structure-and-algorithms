class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> reached(n, false);
        vector<vector<int>> to_paths(n);
        vector<vector<int>> from_paths(n);
        for (const auto& path : connections) {
            from_paths[path[0]].push_back(path[1]);
            to_paths[path[1]].push_back(path[0]);
        }
        int changed_cnt = 0;
        int reached_cnt = 1;
        
        reached[0] = true;
        vector<int> leaves = {0};
        
        while (reached_cnt < n) {
            vector<int> nex_leaves;
            for (const auto& node: leaves) {
                for (const auto& from_node: to_paths[node]) {
                    if (!reached[from_node]) {
                        reached[from_node] = true;
                        reached_cnt++;
                        nex_leaves.push_back(from_node);
                    }
                }
                for (const auto& to_node: from_paths[node]) {
                    if (!reached[to_node]) {
                        reached[to_node] = true;
                        reached_cnt++;
                        changed_cnt++;
                        nex_leaves.push_back(to_node);
                    }
                }
            }

            swap(leaves, nex_leaves);
        }
        
        return changed_cnt;
    }
};

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> edges, r_edges;
        for (const auto& c : connections) {
            edges[c[0]].push_back(c[1]);
            r_edges[c[1]].push_back(c[0]);
        }

        vector<bool> visited(n, false);
        int reorder = 0;
        function<void(int)> dfs;
        dfs = [&](int i) {
            visited[i] = true;
            for (auto j : r_edges[i]) {
                if (!visited[j]) dfs(j);
            }
            for (auto j : edges[i]) {
                if (!visited[j]) {
                    dfs(j);
                    ++reorder;
                }
            }
        };
        dfs(0);

        return reorder;
    }
};
