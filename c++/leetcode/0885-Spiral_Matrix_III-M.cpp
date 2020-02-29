// 885 Spiral Matrix III
// https://leetcode.com/problems/spiral-matrix-iii

// version: 1; create time: 2020-02-08 15:08:04;
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int x = r0, y = c0;
        int lx = r0, hx = r0, ly = c0, hy = c0;
        int dx = 0, dy = 1;
        vector<vector<int>> res;
        while (res.size() < R * C) {
            if (x >= 0 && x < R && y >= 0 && y < C) {
                res.push_back({x, y});
            }
            int nx = x + dx; int ny = y + dy;
            if (nx < lx || nx > hx || ny < ly || ny > hy) {
                if (dx == 0 && dy == 1) {
                    lx -= 1; hx += 1; ly -= 1; hy += 1;
                    dx = 1; dy = 0;
                    x = nx; y = ny;
                } else if (dx == 1 && dy == 0) {
                    dx = 0; dy = -1;
                    x += dx; y += dy;
                } else if (dx == 0 && dy == -1) {
                    dx = -1; dy = 0;
                    x += dx; y += dy;
                } else {
                    dx = 0; dy = 1;
                    x += dx; y += dy;
                }
            } else {
                x = nx; y = ny;
            }
        }
        return res;
    }
};
