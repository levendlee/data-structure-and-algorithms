class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> increasing_path(m, vector<int>(n, 0));
        function<int(int, int)> dfs;
        dfs = [&](int i, int j) {
            if (increasing_path[i][j]) return increasing_path[i][j];
            int path = 1;
            
            constexpr int offsets[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            for (int k = 0; k < 4; ++k) {
                int ii = i + offsets[k][0];
                int jj = j + offsets[k][1];
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || matrix[ii][jj] <= matrix[i][j]) continue;
                path = max(path, dfs(ii, jj) + 1);
            }

            increasing_path[i][j] = path;
            return path;
        };

        int max_increasing_path = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                max_increasing_path = max(max_increasing_path, dfs(i, j));
            }
        }
        return max_increasing_path;
    }
};
