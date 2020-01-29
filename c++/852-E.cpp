class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        const int n = A.size();
        for (int i = 1; i < n - 1; ++i) {
            if (A[i-1] < A[i] && A[i] > A[i+1]) {
                return i;
            }
        }
        return 0;
    }
};