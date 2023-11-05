// 54 Spiral Matrix
// https://leetcode.com/problems/spiral-matrix

// version: 1; create time: 2020-01-19 22:21:56;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();
        if (n == 0) return {};

        int xmin = 0, xmax = m - 1, ymin = 0, ymax = n - 1;
        int x = 0, y = 0;
        int d = 0, dx = 0, dy = 1; // right
        vector<int> spiral;
        while (spiral.size() < m * n) {
            spiral.push_back(matrix[x][y]);
            x += dx; y += dy;
            if (x < xmin || x > xmax || y < ymin || y > ymax) {
                x -= dx; y -= dy;   // undo move
                if (d == 0) {
                    d = 1; dx = 1; dy = 0; ++xmin;
                } else if (d == 1) {
                    d = 2; dx = 0; dy = -1; --ymax;
                } else if (d == 2) {
                    d = 3; dx = -1; dy = 0; --xmax;
                } else if (d == 3) {
                    d = 0; dx = 0; dy = 1; ++ymin;
                }
                x += dx; y += dy;
            }
        }
        return spiral;
    }
};

// 2023/11/04
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        const int m = matrix.size(), n = matrix[0].size();
        int r_lo = 1, r_hi = m - 1, c_lo = 0, c_hi = n - 1;
        int i = 0, j = 0;
        int direction;
        if (n > 1) {
            direction = 0;
        } else {
            direction = 1;
        }
        while (res.size() < m * n) {
            res.push_back(matrix[i][j]);

            if (direction == 0) {
                // right
                j += 1;
                if (j == c_hi) {
                    --c_hi;
                    direction = 1;
                }
            } else if (direction == 1) {
                // down
                i += 1;
                if (i == r_hi) {
                    --r_hi;
                    direction = 2;
                }
            } else if (direction == 2) {
                // left
                j -= 1;
                if (j == c_lo) {
                    ++c_lo;
                    direction = 3;
                }
            } else {
                // up
                i -= 1;
                if (i == r_lo) {
                    ++r_lo;
                    direction = 0;
                }
            }
        }

        return res;
    }
};
