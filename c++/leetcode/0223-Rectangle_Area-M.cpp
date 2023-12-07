// 223 Rectangle Area
// https://leetcode.com/problems/rectangle-area

// version: 1; create time: 2020-02-10 14:38:54;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = std::max(A, E), right = std::min(C, G);
        int down = std::max(F,B), up = std::min(D, H);
        long area = ((long)C-A) * (D-B) + ((long)G-E) * (H-F);
        if (left < right && down < up) {
            area -= ((long)right-left) * (up-down);
        }
        return area;
    }
};

//

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // ax1, ax2, bx1, bx2
        int width =  min(ax2, bx2) - max(ax1, bx1);
        int height = min(ay2, by2) - max(ay1, by1);
        int overlap;
        if (width <= 0 || height <= 0) {
            overlap = 0;
        } else {
            overlap = height * width;
        }
        return (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1) - overlap;
    }
};
