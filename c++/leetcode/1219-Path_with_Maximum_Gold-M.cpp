// 1219 Path with Maximum Gold
// https://leetcode.com/problems/path-with-maximum-gold

// version: 1; create time: 2019-12-01 20:29:00;
class Solution {
private:
    int max_gold_;

    void dfs(vector<vector<int>>& grid, int x, int y, int gold) {
        const int m = grid.size();
        const int n = grid[0].size();
        max_gold_ = std::max(gold, max_gold_);

        constexpr int offsets[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (int i = 0; i < 4; ++i) {
            int xx = x + offsets[i][0];
            int yy = y + offsets[i][1];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n) {
                continue;
            }
            if (grid[xx][yy] == 0) {
                continue;
            }
            auto tmp = grid[xx][yy];
            grid[xx][yy] = 0;
            dfs(grid, xx, yy, gold + tmp);
            grid[xx][yy] = tmp;
        }
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        max_gold_ = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                auto tmp = 0;
                std::swap(grid[i][j], tmp);
                dfs(grid, i, j, tmp);
                std::swap(grid[i][j], tmp);
            }
        }
        return max_gold_;
    }
};
