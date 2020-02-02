class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int n = A.size();
        if (n == 0) return {};

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] < 0) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        vector<int> res;
        int i = lo, j = lo - 1;
        while (i < n || j >= 0) {
            if (j < 0 || i < n && A[i] < -A[j]) {
                res.push_back(A[i] * A[i]); ++i;
            } else {
                res.push_back(A[j] * A[j]); --j;
            }
        }
        return res;
    }
};