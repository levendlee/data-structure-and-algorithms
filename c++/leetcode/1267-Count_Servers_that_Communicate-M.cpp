// 1267 Count Servers that Communicate
// https://leetcode.com/problems/count-servers-that-communicate

// version: 1; create time: 2020-01-29 22:57:22;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0) return 0;
        const int n = grid[0].size();
        if (n == 0) return 0;

        int total = 0;
        vector<int> row_cnts(m, 0);
        vector<int> col_cnts(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++row_cnts[i];
                    ++col_cnts[j];
                    ++total;
                }
            }
        }

        int alone = 0;
        for (int i = 0; i < m; ++i) {
            if (row_cnts[i] > 1) continue;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && row_cnts[i] == 1 && col_cnts[j] == 1) {
                    ++alone;
                }
            }
        }

        return total - alone;
    }
};
