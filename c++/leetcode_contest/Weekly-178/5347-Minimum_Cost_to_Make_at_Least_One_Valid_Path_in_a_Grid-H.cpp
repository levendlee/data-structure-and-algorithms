// 5347. Minimum Cost to Make at Least One Valid Path in a Grid
// https://leetcode.com/contest/weekly-contest-178/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>> pq;
        pq.push({0, 0, 0});
        visited[0][0] = 0;

        while (!pq.empty()) {
            auto cost = -pq.top()[0];
            auto i = pq.top()[1];
            auto j = pq.top()[2];
            pq.pop();
            //cout << i << "," << j << "," << cost << "\n";
            if (i == m-1 && j == n-1) return cost;
            constexpr int offsets[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            const auto d = grid[i][j];
            for (int k = 0; k < 4; ++k) {
                auto ii = i + offsets[k][0];
                auto jj = j + offsets[k][1];
                auto ncost = cost + ((k + 1 == d) ? 0 : 1);
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii][jj] <= ncost) continue;
                visited[ii][jj] = ncost;
                pq.push({-ncost, ii, jj});
            }
        }

        return INT_MAX;
    }
};