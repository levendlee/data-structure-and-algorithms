// 685 Redundant Connection II
// https://leetcode.com/problems/redundant-connection-ii

// version: 1; create time: 2020-02-15 23:05:51;
class Solution {
private:
    bool tpSort(vector<vector<int>>& hashmap, int i, vector<bool>& temp, vector<bool>& perm, vector<int>& path) {
        if (temp[i]) return false;
        if (perm[i]) return true;
        temp[i] = true;
        path.push_back(i);
        for (const auto& pre : hashmap[i]) {
            if (!tpSort(hashmap, pre, temp, perm, path)) return false;
        }
        path.pop_back();
        temp[i] = false;
        perm[i] = true;
        return true;
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int n = edges.size();

        vector<vector<int>> hashmap(n);
        for (const auto& e : edges) {
            hashmap[e[1] - 1].push_back(e[0] - 1);
        }

        vector<int> res1, res2;

        // Case 1: double parent
        for (int i = 0; i < n; ++i) {
            if (hashmap[i].size() == 2) {
                res1 = { hashmap[i][1] + 1, i + 1 };
                res2 = { hashmap[i][0] + 1, i + 1 };
            }
        }

        // Case 1: all single parent, any edge in the loo
        vector<bool> perm(n, false), temp(n, false);
        for (int i = 0; i < n; ++i) {
            vector<int> path;
            if (!tpSort(hashmap, i, perm, temp, path)) {
                int max_idx = -1;
                const int m = path.size();
                for (int i = 0; i < m - 1; ++i) {
                    vector<int> e = { path[i+1] + 1, path[i] + 1 };
                    if (e == res1) return res1;
                    if (e == res2) return res2;
                    int idx = find(edges.begin(), edges.end(), e) - edges.begin();
                    max_idx = max(max_idx, idx);
                }
                return edges[max_idx];
            }
        }

        return res1;
    }
};
