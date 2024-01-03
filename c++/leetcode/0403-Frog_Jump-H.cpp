class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> stones_map;
        for (int u : stones) {
            stones_map[u] = {};
        }
        stones_map[0].insert(0);
        for (int i = 0; i < stones.size(); ++i) {
            int u = stones[i];
            for (auto k : stones_map[u]) {
                int jump[] = {k - 1, k, k + 1};
                for (int j : jump) {
                    auto iter = stones_map.find(u + j);
                    if (iter != stones_map.end()) {
                        iter->second.insert(j);
                    }
                }
            }
        }
        return !stones_map[stones.back()].empty();
    }
};
