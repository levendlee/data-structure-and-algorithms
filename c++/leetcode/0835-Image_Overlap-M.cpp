// 835 Image Overlap
// https://leetcode.com/problems/image-overlap

// version: 1; create time: 2019-12-16 23:32:30;
class Solution {
public:
    int overlap(vector<vector<int>>& A, vector<vector<int>>& B, int offset_x, int offset_y) {
        const int n = A.size();
        int cnt = 0;
        for (int i = 0; i < n - offset_x; ++i) {
            for (int j = 0; j < n - offset_y; ++j) {
                cnt += A[i][j] == 1 && B[i+offset_x][j+offset_y] == 1;
            }
        }
        return cnt;
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int max_overlap = 0;
        const int n = A.size();
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                max_overlap = std::max(max_overlap, overlap(A, B, i, j));
                max_overlap = std::max(max_overlap, overlap(B, A, i, j));
            }
        }
        return max_overlap;
    }
};
