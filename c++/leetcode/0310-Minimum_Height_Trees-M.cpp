// 310 Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees

// version: 1; create time: 2020-02-16 00:52:58;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};

        vector<vector<int>> hashmap(n);
        for (const auto& e : edges) {
            hashmap[e[0]].push_back(e[1]);
            hashmap[e[1]].push_back(e[0]);
        }

        vector<int> nodes;
        for (int i = 0; i < n; ++i) nodes.push_back(i);

        while (n > 2) {
            vector<int> leaves;
            for (auto node : nodes) {
                if (hashmap[node].size() == 1) {
                    leaves.push_back(node);
                }
            }
            for (auto node : leaves) {
                auto other = hashmap[node][0];
                auto iter0 = find(hashmap[other].begin(), hashmap[other].end(), node);
                hashmap[other].erase(iter0);
                auto iter1 = find(nodes.begin(), nodes.end(), node);
                nodes.erase(iter1);
            }
            n -= leaves.size();
        }

        return vector<int>(nodes.begin(), nodes.end());
    }
};

//

// T: O(N^2); S: O(N^2);
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> min_dist(n, vector<int>(n, INT_MAX));

        unordered_map<int, vector<int>> edge_map;
        for (const auto& e : edges) {
            edge_map[e[0]].push_back(e[1]);
            edge_map[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> bfs;
        for (int i = 0; i < n; ++i) {
            bfs.push({i, i});
            min_dist[i][i] = 0;
        }

        int dist = 0;
        while (!bfs.empty()) {
            ++dist;
            int search_space = bfs.size();
            for (int k = 0; k < search_space; ++k) {
                auto [src, dst] = bfs.front();
                bfs.pop();
                for (int next : edge_map[dst]) {
                    if (min_dist[src][next] <= dist) continue;
                    min_dist[src][next] = dist;
                    bfs.push({src, next});
                }
            }
        }

        vector<int> res;
        int min_height = INT_MAX;
        for (int i = 0 ; i < n; ++i) {
            min_height = min(min_height, *max_element(min_dist[i].begin(), min_dist[i].end())); 
        }
        for (int i = 0 ; i < n; ++i) {
            if (min_height == *max_element(min_dist[i].begin(), min_dist[i].end())) {
                res.push_back(i);
            }
        }
        return res;
    }
};

//

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<unordered_set<int>> adj_list(n);
        for (const auto& e : edges) {
            adj_list[e[0]].insert(e[1]);
            adj_list[e[1]].insert(e[0]);
        }

        vector<bool> removed(n, false);
        auto find_leaves = [&]() {
            vector<int> leaves;
            for (int i = 0; i < n; ++i) {
                if (removed[i]) continue;

                const auto& l = adj_list[i];
                if (l.size() <= 1) {
                    leaves.push_back(i);
                }
            }
            return leaves;
        };

        auto prune_leaves = [&](const vector<int>& leaves) {
            for (int n : leaves) {
                for (int adj : adj_list[n]) {
                    adj_list[adj].erase(n);
                }
                removed[n] = true;
            }
        };

        while (accumulate(removed.begin(), removed.end(), 0) < n - 2) {
            auto leaves = find_leaves();
            prune_leaves(leaves);
        }

        return find_leaves();
    }
};