// 221 Maximal Square
// https://leetcode.com/problems/maximal-square

// version: 1; create time: 2019-11-06 23:02:16;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;

        int maxl = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            for (int j = 0; j < n; ++j) {
                auto maxh = dp[j];
                int cur_min = INT_MAX;
                for (int k = j; k < n; ++k) {
                    cur_min = std::min(cur_min, dp[k]);
                    if (cur_min < k - j + 1) break;
                    maxl = std::max(maxl, k - j + 1);
                }
            }
        }

        return maxl * maxl;
    }
};

// 2023/11/02

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int max_square = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != '1') continue;
                dp[i + 1][j + 1] = min({dp[i + 1][j], dp[i][j + 1], dp[i][j]}) + 1;
                max_square = max(max_square, dp[i + 1][j + 1]);
            }
        }
        return max_square * max_square;
    }
};
