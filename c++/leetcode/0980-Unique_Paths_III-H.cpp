// 980 Unique Paths III
// https://leetcode.com/problems/unique-paths-iii

// version: 1; create time: 2020-01-04 17:40:42;
class Solution {
private:
    int m_;
    int n_;
    unordered_map<int, int> mem_;

public:
    int dfs(const vector<vector<int>>& grid, int i, int j, int cnt, int hash) {
        if (grid[i][j] == 2) {
            return cnt == 0;
        }

        const int idx = i * n_ + j;
        const int mask = 1 << idx;
        if (hash & mask) return 0;
        hash = hash & ((1 << 20) - 1) | mask | (idx << 21);
        if (mem_.count(hash)) return mem_[hash];

        constexpr int offsets[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int res = 0;
        for (int k = 0; k < 4; ++k) {
            const int ii = i + offsets[k][0];
            const int jj = j + offsets[k][1];
            if (ii < 0 || ii >= m_ || jj < 0 || jj >= n_ || grid[ii][jj] == -1) continue;
            res += dfs(grid, ii, jj, cnt - 1, hash);
        }
        mem_[hash] = res;
        return res;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        const int m = grid.size(); m_ = m;
        if (m == 0) return 0;
        const int n = grid[0].size(); n_ = n;
        if (n == 0) return 0;

        int empty_cnt = 0;
        int start_i = 0, start_j = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                empty_cnt += (grid[i][j] == 0);
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
            }
        }
        return dfs(grid, start_i, start_j, empty_cnt + 1, 0);
    }
};
