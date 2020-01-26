class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        const int n = A.size();

        vector<int> rem(K, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            auto r = sum % K;
            ++rem[r >= 0 ? r : r + K];
        }
        ++rem[0];

        int cnt = 0;
        for (int i = 0; i < K; ++i) {
            if (rem[i] >= 2) {
                cnt += rem[i] * (rem[i] - 1);
            }
        }
        return cnt / 2;
    }
};