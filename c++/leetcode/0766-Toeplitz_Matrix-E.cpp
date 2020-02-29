// 766 Toeplitz Matrix
// https://leetcode.com/problems/toeplitz-matrix

// version: 1; create time: 2020-02-07 22:30:59;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return true;
        const int n = matrix[0].size();
        if (n == 0) return true;

        for (int i = 0; i < m; ++i) {
            int x = i, y = 0;
            while (++x < m && ++y < n) {
                //std::cout << x << "," << y << "\n";
                if (matrix[x][y] != matrix[i][0]) return false;
            }
        }

        for (int j = 0; j < n; ++j) {
            int x = 0, y = j;
            while (++x < m && ++y < n) {
                //std::cout << x << "," << y << "\n";
                if (matrix[x][y] != matrix[0][j]) return false;
            }
        }

        return true;
    }
};
