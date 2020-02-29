// 542 01 Matrix
// https://leetcode.com/problems/01-matrix

// version: 1; create time: 2020-02-16 15:33:27;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return matrix;
        const int n = matrix[0].size();
        if (n == 0) return matrix;

        queue<vector<int>> bfs;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    bfs.push({i, j});
            }
        }

        int dist = 0;
        while (!bfs.empty()) {
            const int size = bfs.size();
            for (int t = 0; t < size; ++t) {
                auto i = bfs.front()[0], j = bfs.front()[1]; bfs.pop();
                constexpr int adj[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
                for (int k = 0; k < 4; ++k) {
                    auto ii = i + adj[k][0];
                    auto jj = j + adj[k][1];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n || matrix[ii][jj] != 1) continue;
                    matrix[ii][jj] = -(dist + 1);
                    bfs.push({ii, jj});
                }
            }
            ++dist;
        }

        for (auto& row : matrix)
            for (auto& elem : row)
                elem = abs(elem);

        return matrix;
    }
};
