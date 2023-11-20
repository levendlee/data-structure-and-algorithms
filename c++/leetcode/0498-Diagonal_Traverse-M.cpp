// 498 Diagonal Traverse
// https://leetcode.com/problems/diagonal-traverse

// version: 1; create time: 2020-01-30 22:14:46;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();
        if (n == 0) return {};

        vector<int> res;
        int x = 0, y = 0;
        int dx = -1, dy = 1;
        while (res.size() < m * n) {
            res.push_back(matrix[x][y]);
            int px = x, py = y;
            x += dx; y += dy;
            if (x < 0 || x >= m || y < 0 || y >= n) {
                if (dx == 1) {
                    if (px == m - 1) {
                        x = px;
                        y = py + 1;
                    } else {
                        x = px + 1;
                        y = py;
                    }
                } else {
                    if (py == n - 1) {
                        x = px + 1;
                        y = py;
                    } else {
                        x = px;
                        y = py + 1;
                    }
                }
                dx = -dx; dy = -dy;
            }
        }
        return res;
    }
};

//

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();

        vector<int> res;
        int i = 0, j = 0;
        bool d = false;
        while (res.size() < m * n) {
            if (i >= 0 && i < m && j >= 0 && j < n) {
                res.push_back(mat[i][j]);
            }
            if (d) {
                ++i;
                --j;
            } else {
                --i;
                ++j;
            }
            if (i < 0) {
                d = !d;
                i = 0;
            } else if (i >= m) {
                d = !d;
                i = m - 1;
                j += 2;
            } else if (j < 0) {
                d = !d;
                j = 0;
            } else if (j >= n) {
                d = !d;
                j = n - 1;
                i += 2;
            }
        }

        return res;
    }
};
