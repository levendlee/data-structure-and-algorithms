class Solution {
public:
    string shortestSuperstring(vector<string>& A)
    {
        if (A.empty()) return "";

        const int n = A.size();
        vector<vector<int8_t>> overlaps(n, vector<int8_t>(n, 0));
        for (int i = 0; i < n; ++i) {
            const auto& s0 = A[i];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                const auto& s1 = A[j];
                const int nn = std::min(s0.size(), s1.size());
                for (int k = nn; k >= 1; --k) {
                    if (std::equal(s0.end() - k, s0.end(), s1.begin(), s1.begin() + k)) {
                        overlaps[i][j] = k;
                        break;
                    }
                }
            }
        }

        const int seen_cnts = 1 << n;
        vector<vector<int>> dp(seen_cnts, vector<int>(n, 0));
        vector<vector<int>> parent(seen_cnts, vector<int>(n, -1));

        for (int seen = 0; seen < seen_cnts; ++seen) {
            for (int i = 0; i < n; ++i) {
                if (!(seen & (1 << i))) continue;
                for (int j = 0; j < n; ++j) {
                    if (seen & (1 << j)) continue;
                    int new_size = dp[seen][i] + overlaps[i][j];
                    int new_seen = seen | (1 << j);
                    if (new_size >= dp[new_seen][j]) {
                        dp[new_seen][j] = new_size;
                        parent[new_seen][j] = i;
                    }
                }
            }
        }

        const int full_seen = (1 << n) - 1;
        int max_last = std::max_element(dp[full_seen].begin(), dp[full_seen].end()) - dp[full_seen].begin();

        std::string ans;
        int cur_idx = max_last;
        int cur_mask = full_seen;
        // backtracing
        for (int i = 0; i < n; ++i) {
            int pre_idx = parent[cur_mask][cur_idx];
            int pre_mask = cur_mask ^ (1 << cur_idx);
            int overlap = pre_idx != -1 ? overlaps[pre_idx][cur_idx] : 0;

            ans = A[cur_idx].substr(overlap) + ans;

            cur_idx = pre_idx;
            cur_mask = pre_mask;
        }

        return ans;
    }
};