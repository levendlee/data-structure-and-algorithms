class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        int dp0 = 0;    // Previous swapped
        int dp1 = 0;    // Previous not swapped
        for (int i = 0; i < n; ++i) {
            int ndp0 = n + 1;
            int ndp1 = n + 1;
            if (i == 0 || (A[i-1] < B[i]) && (B[i-1] < A[i])) {
                ndp0 = dp1 + 1;
                ndp1 = dp0;
            }
            if (i == 0 || (A[i-1] < A[i]) && (B[i-1] < B[i])) {
                ndp0 = std::min(ndp0, dp0 + 1);
                ndp1 = std::min(ndp1, dp1);
            }
            dp0 = ndp0;
            dp1 = ndp1;
        }
        return std::min(dp0, dp1);
    }
};