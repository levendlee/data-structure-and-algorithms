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

//

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        for (int r = 0; r < m; ++r) {
            int i = r, j = 0;
            while (i < m && j < n) {
                if (matrix[i][j] != matrix[r][0]) return false;
                ++i;
                ++j;
            }
        }

        for (int c = 1; c < n; ++ c) {
            int i = 0, j = c;
            while (i < m && j < n) {
                if (matrix[i][j] != matrix[0][c]) return false;
                ++i;
                ++j;
            }
        }

        return true;
    }
};

//

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && j > 0 && matrix[i-1][j-1] != matrix[i][j]) return false;
            }
        }

        return true;
    }
};
