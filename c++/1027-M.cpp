class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        const int n = A.size();
        int longest = 0;
        map<pair<int, int>, int> dp;
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                const int d = A[j] - A[i];
                auto cur = std::make_pair(j, A[j] - A[i]);
                auto pre = std::make_pair(i, d);
                dp[cur] = std::max(dp[cur], (dp.count(pre) ? dp[pre] : 1) + 1);
                longest = std::max(dp[cur], longest);
            }
        }
        return longest;
    }
};