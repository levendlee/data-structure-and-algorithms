// 74 Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix

// version: 1; create time: 2020-01-07 22:36:50;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;

        int lo = 0, hi = m * n - 1, mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] < target) {
                lo = mid + 1;
            } else if (matrix[i][j] > target) {
                hi = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
