// 1192 Critical Connections in a Network
// https://leetcode.com/problems/critical-connections-in-a-network

// version: 1; create time: 2019-11-14 22:29:41;
class Solution {
private:
    vector<vector<int>> res_;

    vector<vector<int>> edges_;
    vector<int> disc_;
    vector<int> low_;
    int times_;

public:
    void dfs(int u, int p) {
        disc_[u] = low_[u] = ++times_;

        for (const auto& v : edges_[u]) {
            if (disc_[v] == INT_MIN) {
                dfs(v, u);
                low_[u] = std::min(low_[u], low_[v]);
                if (low_[v] > disc_[u]) {
                    res_.push_back({u, v});
                }
            } else if (v != p) {
                low_[u] = std::min(low_[u], low_[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if (n == 0) return {};

        edges_.resize(n);
        disc_.resize(n, INT_MIN);
        low_.resize(n, INT_MIN);
        times_ = 0;

        for (const auto& vec : connections) {
            edges_[vec[0]].push_back(vec[1]);
            edges_[vec[1]].push_back(vec[0]);
        }

        dfs(0, -1);
        return res_;
    }
};
