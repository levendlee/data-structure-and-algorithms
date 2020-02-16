class Solution {
private:
    int sharedChars(const vector<string>& A, int i, int j) {
        const int n0 = A[i].size(), n1 = A[j].size();
        int shared = 0;
        for (int size = std::min(n0, n1); size >= 1; --size) {
            auto suffix = A[i].substr(n0 - size, size);
            auto prefix = A[j].substr(0, size);
            if (suffix == prefix) {
                shared = size; break;
            }
        }
        return shared;
    }

public:
    string shortestSuperstring(vector<string>& A) {
        const int n = A.size();

        vector<vector<int>> shared(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                shared[i][j] = sharedChars(A, i, j);
            }
        }

        auto count_bits = [&](int num) {
            int bits = 0;
            while (num) {
                num = num & (num - 1);
                ++bits;
            }
            return bits;
        };

        const int target = (1 << n) - 1;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        vector<vector<int>> parent(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][1 << i] = A[i].size();
        }

        for (int seen = 0; seen <= target; ++seen) {
            for (int i = 0; i < n; ++i) {
                if (!(seen & (1 << i))) continue;
                for (int j = 0; j < n; ++j) {
                    if (seen & (1 << j)) continue;
                    auto n_seen = seen | (1 << j);
                    auto n_size = dp[i][seen] + A[j].size() - shared[i][j];
                    if (dp[j][n_seen] == 0 || dp[j][n_seen] > n_size) {
                        dp[j][n_seen] = n_size;
                        parent[j][n_seen] = i;
                    }
                }
            }
        }

        int shortest_idx = 0, shortest = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dp[i][target] < shortest) {
                shortest = dp[i][target];
                shortest_idx = i;
            }
        }

        string res;
        int cur = shortest_idx;
        int seen = target;

        for (int i = n - 1; i >= 0; --i) {
            if (i == 0) {
                res = A[cur] + res;
            } else {
                int pre = parent[cur][seen];
                res = A[cur].substr(shared[pre][cur]) + res;
                seen = seen ^ (1 << cur);
                cur = pre;
            }
        }

        return res;
    }
};