// 240 Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii

// version: 1; create time: 2019-12-30 11:34:15;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (m == 0) return false;
        const int n = matrix[0].size();
        if (n == 0) return false;
        
        int i = 0, j = n-1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};

//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int lo = 0, hi = m - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (matrix[mid][0] > target) {
                hi = mid - 1;
            } else if (matrix[mid][0] < target) {
                lo = mid;
            } else {
                return true;
            }
        }
        int end = lo;

        lo = 0, hi = m - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (matrix[mid][n - 1] < target) {
                lo = mid + 1;
            } else if (matrix[mid][n - 1] > target) {
                hi = mid;
            } else {
                return true;
            }
        }
        int start = lo;

        for (int i = start; i <= end; ++i) {
            auto iter = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if (iter != matrix[i].end() && *iter == target) return true;
        }
        return false;
    }
};

