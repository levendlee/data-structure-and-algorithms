class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        std::unordered_map<int, std::unordered_set<int>> hashed_roads;
        for (const auto& r : roads) {
            hashed_roads[r[0]].insert(r[1]);
            hashed_roads[r[1]].insert(r[0]);
        }
        
        int max_rank = 0;
        for (const auto& [i0, j0s] : hashed_roads) {
            for (const auto& [i1, j1s] : hashed_roads) {
                if (i0 <= i1) continue;
                int connection = j0s.size() + j1s.size() - j0s.count(i1);
                max_rank = max_rank > connection ? max_rank : connection;
            }
        }

        return max_rank;
    }
};
