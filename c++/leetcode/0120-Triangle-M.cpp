class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int m = triangle.size();

        for (int i = 1; i < m; ++i) {
            int n = triangle[i].size();
            for (int j = 0; j < n; ++j) {
                triangle[i][j] += std::min(j == 0 ? INT_MAX : triangle[i-1][j-1],
                                           j == n - 1 ? INT_MAX : triangle[i-1][j]);
            }
        }

        return *std::min_element(triangle[m - 1].begin(), triangle[m - 1].end());
    }
};
