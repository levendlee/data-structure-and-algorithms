class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n_rows = wall.size();
        if (n_rows == 0) return 0;

        std::unordered_map<int, int> cumsum_map;
        for (auto& row: wall) {
            int cumsum = 0;
            for (int i = 0; i < row.size() - 1; ++i) {
                cumsum += row[i];
                cumsum_map[cumsum]++;
            }
        }

        int max_apperances = 0;
        for (auto& p: cumsum_map) {
            max_apperances = std::max(p.second, max_apperances);
        }

        return n_rows - max_apperances;
    }
};