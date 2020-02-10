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