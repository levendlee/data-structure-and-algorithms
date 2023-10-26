class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col_used(n, false), diag_used1(n * 2 - 1, false), diag_used2(n * 2 - 1, false);

        auto calc_diag_idx1 = [&](int i, int j) {
            return (j - i) + n - 1;
        };

        auto calc_diag_idx2 = [&](int i, int j) {
            i = n - 1 - i;
            return (j - i) + n - 1;
        };

        function<int(int)> backtracing;
        backtracing = [&](int i) {
            if (i == n) return 1;

            int counts = 0;
            for (int j = 0; j < n; ++j) {
                int diag_idx1 = calc_diag_idx1(i, j);
                int diag_idx2 = calc_diag_idx2(i, j);
                if (!col_used[j] && !diag_used1[diag_idx1] && !diag_used2[diag_idx2]) {
                    col_used[j] = true;
                    diag_used1[diag_idx1] = true;
                    diag_used2[diag_idx2] = true;
                    counts += backtracing(i + 1);
                    col_used[j] = false;
                    diag_used1[diag_idx1] = false;
                    diag_used2[diag_idx2] = false;
                }
            }
            return counts;
        };

        return backtracing(0);
    }
};
