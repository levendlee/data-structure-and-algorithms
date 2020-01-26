class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;

        /*
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            int row_sum = 0;
            for (int j = 0; j < n; ++j) {
                row_sum += matrix[i][j];
                sums[i+1][j+1] = sums[i][j+1] + row_sum;
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 1; i + k <= m && j + k <= n; ++k) {
                    //std::cout << k << "#\n";
                    if (sums[i+k][j+k] - sums[i+k][j] - sums[i][j+k] + sums[i][j] == k * k) {
                        //std::cout << k << "\n";
                        cnt++;
                    }
                }
            }
        }
        */

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] && i && j) {
                    matrix[i][j] = std::min(matrix[i-1][j-1], std::min(matrix[i-1][j], matrix[i][j-1])) + 1;
                }
                cnt += matrix[i][j];
            }
        }
        return cnt;
    }
};