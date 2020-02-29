// 1292 Maximum Side Length of a Square with Sum Less than or Equal to Threshold
// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold

// version: 1; create time: 2020-01-18 20:52:27;
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int m = mat.size();
        if (m == 0) return 0;
        const int n = mat[0].size();
        if (n == 0) return 0;

        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            int rowsum = 0;
            for (int j = 1; j <= n; ++j) {
                rowsum += mat[i-1][j-1];
                sums[i][j] = sums[i-1][j] + rowsum;
            }
        }

        int k = 1;
        for (int i = 0; i + k <= m; ++i) {
            for (int j = 0; j + k <= n; ++j) {
                while (true) {
                    if (i + k <= m && j + k <= n) {
                        auto area = sums[i+k][j+k] - sums[i+k][j] - sums[i][j+k] + sums[i][j];
                        if (area <= threshold) {
                            ++k;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        return k - 1;
    }
};
