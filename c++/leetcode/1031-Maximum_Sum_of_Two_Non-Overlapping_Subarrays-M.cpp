// 1031 Maximum Sum of Two Non-Overlapping Subarrays
// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays

// version: 1; create time: 2020-01-26 23:02:01;
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        const int n = A.size();
        vector<int> maxL(n + 1, 0);
        vector<int> maxM(n + 1, 0);
        int sumL = 0, sumM = 0, maxV = 0;
        for (int i = 0; i < n; ++i) {
            sumL += A[i];
            sumM += A[i];
            if (i >= L - 1) {
                maxL[i+1] = std::max(maxL[i], sumL);
                maxV = std::max(maxV, sumL + maxM[i+1-L]);
                sumL -= A[i-L+1];
            }
            if (i >= M - 1) {
                maxM[i+1] = std::max(maxM[i], sumM);
                maxV = std::max(maxV, sumM + maxL[i+1-M]);
                sumM -= A[i-M+1];
            }
        }
        return maxV;
    }
};
