class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;

        // O(N^4)
        /*
        vector<vector<int64_t>> sum_matrix(m + 1, vector<int64_t>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            int row_sum = 0;
            for (int j = 0; j < n; ++j) {
                row_sum += matrix[i][j];
                sum_matrix[i+1][j+1] = sum_matrix[i][j+1] + row_sum;
            }
        }

        int cnt = 0;
        for (int i0 = 0; i0 <= m; ++i0) {
            for (int j0 = 0; j0 <= n; ++j0) {
                for (int i1 = i0 + 1; i1 <= m; ++i1) {
                    for (int j1 = j0 + 1; j1 <= n; ++j1) {
                        if (sum_matrix[i1][j1] - sum_matrix[i0][j1] - sum_matrix[i1][j0] + sum_matrix[i0][j0] == target) {
                            ++cnt;
                        }
                    }
                }
            }
        }
        */

        // O(N^3)
        /*
        vector<int64_t> row_sums(n + 1, 0);
        unordered_map<int, int64_t> range_acc_sums;
        unordered_map<int64_t, int> range_all_sums;

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_sums[j + 1] = row_sums[j] + matrix[i][j];
            }

            for (int s = 0; s <= n; ++s) {
                for (int e = s + 1; e <= n; ++e) {
                    const int range_sum = row_sums[e] - row_sums[s];

                    const int range_hash = (s << 10) | e;
                    auto& cur_acc = range_acc_sums[range_hash];
                    cur_acc += range_sum;

                    const int64_t range_sum_hash = (static_cast<int64_t>(range_hash) << 44) | \
                                                   (static_cast<int64_t>(range_sum - cur_acc) & ((1UL << 44) - 1));
                    auto& cur_all = range_all_sums[range_sum_hash];
                    cur_all++;

                    const int64_t new_range_sum_hash = (static_cast<int64_t>(range_hash) << 44) | \
                                                    (static_cast<int64_t>(target - cur_acc) & ((1UL << 44) - 1));
                    if (range_all_sums.count(new_range_sum_hash)) {
                        cnt += range_all_sums[new_range_sum_hash];
                    }
                }
            }
        }
        */

        // O(N^3). Change loop order.
        // Limit 300 * 300 * 1000 ~= 10^8
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sums[i+1][j+1] += sums[i+1][j] + matrix[i][j];
            }
        }

        int cnt = 0;
        for (int s = 0; s <= n; ++s) {
            for (int e = s + 1; e <= n; ++e) {
                unordered_map<int, int> counter;
                int cur = 0;
                for (int i = 0; i <= m; ++i) {
                    cur += sums[i][e] - sums[i][s];
                    cnt += counter[cur-target];
                    ++counter[cur];
                }
            }
        }

        return cnt;
    }
};