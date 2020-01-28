class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int M = A.size();
        if (M == 0) return {{}};
        const int K = A[0].size();
        if (K == 0) return {{}};
        const int N = B[0].size();
        if (N == 0) return {{}};

        vector<vector<int>> C(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            for (int k = 0; k < K; ++k) {
                if (!A[i][k]) continue;
                for (int j = 0; j < N; ++j) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
};