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