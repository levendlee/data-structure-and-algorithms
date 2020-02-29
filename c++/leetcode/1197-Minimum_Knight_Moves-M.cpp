// 1197 Minimum Knight Moves
// https://leetcode.com/problems/minimum-knight-moves

// version: 1; create time: 2019-12-01 22:07:51;
class Solution {
public:
    int minKnightMoves(int x, int y) {
        int maxL = std::max(abs(x), abs(y));
        int minL = std::min(abs(x), abs(y));
        int delta = maxL - minL;
        if (maxL == 1 && minL == 0) {
            return 3;
        }
        if (maxL == 2 && minL == 2) {
            return 4;
        }
        // Baseline: (2, 1), move by delta = 1
        if (delta > minL) {
            // Improve: (2, 1) + (2, -1), move by delta = 4; 4 steps to 2 steps.
            return delta - 2 * ((delta - minL) / 4);
        } else {
            // Improve: (2, 1) + (1, 2), move by delta = 0; minL move 3; 0 steps to 2 steps.
            // Improve: (-1, 2) + (2, 1) + (2, -1), move by delta = 1; minL move 2; 1 steps to 3 steps;
            // Improve: (2, -1) + (-1, 2), move by delta = 0; minL move 1; 0 steps to 2 steps.
            return delta - 2 * floor((float)(delta - minL) / 3);
        }
    }
};
