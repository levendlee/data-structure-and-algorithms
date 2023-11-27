class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        vector<int> row_cnt(m, 0), col_cnt(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++row_cnt[i];
                    ++col_cnt[j];
                }
            }
        }

        int min_row_dist = INT_MAX, min_col_dist = INT_MAX;
        // row 0
        auto calc_total_dist = [](const vector<int>& cnt) {
            const int size = cnt.size();
            int cur_dist = 0;
            int l_cnt = 0, r_cnt = 0;
            // row 0 or col 0
            for (int i = 1; i < size; ++i) {
                cur_dist += i * cnt[i];
                r_cnt += cnt[i];
            }
            int min_dist = cur_dist;
            // row 1 to row m - 1
            for (int i = 1; i < size; ++i) {
                l_cnt += cnt[i - 1];
                cur_dist = cur_dist - r_cnt + l_cnt;
                r_cnt -= cnt[i];
                min_dist = min(cur_dist, min_dist);
            }
            return min_dist;
        };

        return calc_total_dist(row_cnt) + calc_total_dist(col_cnt);
    }
};
