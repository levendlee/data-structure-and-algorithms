// 304 Range Sum Query 2D - Immutable
// https://leetcode.com/problems/range-sum-query-2d-immutable

// version: 1; create time: 2019-12-26 20:50:40;
class NumMatrix {
private:
    vector<vector<int>> sums_;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return;
        const int n = matrix[0].size();
        if (n == 0) return;
        sums_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sums_[i+1][j+1] = sums_[i+1][j] + matrix[i][j];
            }
            for (int j = 0; j < n; ++j) {
                sums_[i+1][j+1] += sums_[i][j+1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums_[row2+1][col2+1] - sums_[row1][col2+1] - sums_[row2+1][col1] + sums_[row1][col1];
    }
};

