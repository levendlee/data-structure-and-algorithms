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