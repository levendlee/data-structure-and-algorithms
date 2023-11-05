// 73 Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes

// version: 1; create time: 2020-02-07 23:40:30;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return;
        const int n = matrix[0].size();
        if (n == 0) return;

        bool set_first_row = false;
        bool set_first_col = false;

        for (int i = 0; i < m; ++i) {
            set_first_row |= matrix[i][0] == 0;
        }
        for (int j = 0; j < n; ++j) {
            set_first_col |= matrix[0][j] == 0;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (set_first_row) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (set_first_col) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};


// 2023/11/04

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        bool row0 = false, col0 = false;
        for (int i = 0; i < m; ++i) {
            col0 |= matrix[i][0] == 0;
        }
        for (int i = 0; i < n; ++i) {
            row0 |= matrix[0][i] == 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    std::cout << "Fuck!" << i << ", " << j << "\n";
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (row0) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }

        if (col0) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
