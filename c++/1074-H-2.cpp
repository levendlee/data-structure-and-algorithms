class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;

        vector<vector<int>> rowsums(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowsums[i][j+1] = rowsums[i][j] + matrix[i][j];
            }
        }

        int res = 0;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                unordered_map<int, int> sum_cnt;
                sum_cnt[0] = 1;
                int acc_sum = 0;
                for (int i = 0; i < m; ++i) {
                    int cur_sum = rowsums[i][r+1] - rowsums[i][l];
                    acc_sum += cur_sum;
                    res += sum_cnt[acc_sum - target];
                    ++sum_cnt[acc_sum];
                }
            }
        }

        return res;
    }
};