class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();

        
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; ++i) {
            lo = min(lo, matrix[i][0]);
            hi = max(hi, matrix[i][n - 1]);
        }
        while (lo < hi) {
            int mid = hi - lo == 1 ? lo : (lo + hi) / 2;
            int less_cnt = 0;
            int less_or_equal_cnt = 0;
            for (int i = 0; i < n; ++i) {
                auto iter = lower_bound(matrix[i].begin(), matrix[i].end(), mid);
                if (iter == matrix[i].end()) {
                    less_cnt += n;
                } else {
                    less_cnt += iter - matrix[i].begin();
                }
                iter = upper_bound(matrix[i].begin(), matrix[i].end(), mid);
                if (iter == matrix[i].end()) {
                    less_or_equal_cnt += n;
                } else {
                    less_or_equal_cnt += iter - matrix[i].begin();
                }
            }
            if (less_cnt >= k) {
                hi = mid;
            } else if (less_cnt <= k && less_or_equal_cnt >= k){
                return mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
