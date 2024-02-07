class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> adj_list;
        for (const auto& e : edges) {
            adj_list[e[0]].insert(e[1]);
            adj_list[e[1]].insert(e[0]);
        }
        
        vector<int> odd_degree_nodes;
        for (const auto& [node, vec] : adj_list) {
            if (vec.size() & 0x1) {
                odd_degree_nodes.push_back(node);
                if (odd_degree_nodes.size() > 4) {
                    return false;
                }
            }
        }

        if (odd_degree_nodes.empty()) {
            return true;
        }

        if (odd_degree_nodes.size() == 1 || odd_degree_nodes.size() == 3) {
            return false;
        }

        auto is_connected = [&](int i, int j) {
            return adj_list[i].count(j);
        };

        if (odd_degree_nodes.size() == 2) {
            int a = odd_degree_nodes[0];
            int b = odd_degree_nodes[1];
            if (!adj_list[a].count(b)) {
                return true;
            }
            for (int i = 1; i <= n; ++i) {
                if (!is_connected(a, i) && !is_connected(b, i)) {
                    return true;
                }
            }
            return false;
        }

        int a = odd_degree_nodes[0];
        int b = odd_degree_nodes[1];
        int c = odd_degree_nodes[2];
        int d = odd_degree_nodes[3];

        return !is_connected(a, b) && !is_connected(c, d) || !is_connected(a, c) && !is_connected(b, d) || !is_connected(a, d) && !is_connected(b, c);
    }
};