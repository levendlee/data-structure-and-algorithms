class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        const int n = A.size();
        int i = 0, j = 0;
        int len = 0;
        int count1 = 0;
        while (j < n) {
            count1 += A[j] == 1;
            while ((j - i + 1) - count1 > K) {
                count1 -= A[i++] == 1;
            }
            len = std::max(len, j - i + 1);
            ++j;
        }
        return len;
    }
};