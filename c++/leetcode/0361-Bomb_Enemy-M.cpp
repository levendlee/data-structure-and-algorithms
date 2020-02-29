// 361 Bomb Enemy
// https://leetcode.com/problems/bomb-enemy

// version: 1; create time: 2020-01-26 17:23:57;
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        const int m = grid.size();
        if (m == 0) return 0;
        const int n = grid[0].size();
        if (n == 0) return 0;

        // O(MN) time. O(MN) space. -> Can be optimized to use O(N) space.
        vector<vector<int>> counter(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            int k = 0, cnt = 0;
            for (int j = 0; j <= n; ++j) {
                if (j == n || grid[i][j] == 'W') {
                    for (int t = k; t < j; ++t) {
                        if (grid[i][t] == '0')
                            counter[i][t] += cnt;
                    }
                    k = j + 1;
                    cnt = 0;
                } else {
                    cnt += grid[i][j] == 'E';
                }
            }
        }

        int max_kill = 0;
        for (int j = 0; j < n; ++j) {
            int k = 0, cnt = 0;
            for (int i = 0; i <= m; ++i) {
                if (i == m || grid[i][j] == 'W') {
                    for (int t = k; t < i; ++t) {
                        if (grid[t][j] == '0')
                            counter[t][j] += cnt;
                        max_kill = std::max(max_kill, counter[t][j]);
                    }
                    k = i + 1;
                    cnt = 0;
                } else {
                    cnt += grid[i][j] == 'E';
                }
            }
        }

        return max_kill;
    }
};
