class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;

        /*
        vector<vector<int>> rowsums(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowsums[i][j+1] = rowsums[i][j] + matrix[i][j];
            }
        }

        int max_sum = INT_MIN;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                set<int> area;
                area.insert(0);
                int sum = 0;
                for (int i = 0; i < m; ++i) {
                    sum += rowsums[i][r+1] - rowsums[i][l];
                    auto iter = area.lower_bound(sum - k);
                    if (iter != area.end()) {
                        max_sum = max(max_sum, sum - *iter);
                    }
                    area.insert(sum);
                }
            }
        }
        */
        int max_sum = INT_MIN;
        for (int l = 0; l < n; ++l) {
            vector<int> rowsum(m, 0);
            for (int r = l; r < n; ++r) {
                for (int i = 0; i < m; ++i) {
                    rowsum[i] += matrix[i][r];
                }
                set<int> area;
                area.insert(0);
                int sum = 0;
                for (int i = 0; i < m; ++i) {
                    sum += rowsum[i];
                    auto iter = area.lower_bound(sum - k);
                    if (iter != area.end()) {
                        max_sum = max(max_sum, sum - *iter);
                    }
                    area.insert(sum);
                }
            }
        }
        return max_sum;
    }
};