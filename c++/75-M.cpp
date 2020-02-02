class Solution {
public:
    void sortColors(vector<int>& A) {
        const int n = A.size();
        int idx0 = 0, idx1 = 0, idx2 = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                A[idx2++] = 2;
                A[idx1++] = 1;
                A[idx0++] = 0;
            } else if (A[i] == 1) {
                A[idx2++] = 2;
                A[idx1++] = 1;
            } else {
                A[idx2++] = 2;
            }
        }
    }
};