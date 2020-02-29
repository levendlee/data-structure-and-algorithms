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

