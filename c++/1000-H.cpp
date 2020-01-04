class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        const int N = stones.size();
        if (N == 1) return 0;
        if ((N < K) || (N - K) % (K - 1)) return -1;


        vector<int> sums(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            sums[i+1] = sums[i] + stones[i];
        }

        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int m = K; m <= N; ++m) {
            for (int i = 0; i + m <= N; ++i) {
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid += K - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
                }
                if (dp[i][j] == INT_MAX) {
                    dp[i][j] = 0;
                }
                if ((m - 1) % (K - 1) == 0) {
                    dp[i][j] += sums[j+1] - sums[i];
                }
            }
        }

        return dp[0][N-1] == 0 ? -1 : dp[0][N-1];
    }
};