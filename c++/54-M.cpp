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