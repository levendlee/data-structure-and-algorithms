// 943 Find the Shortest Superstring
// https://leetcode.com/problems/find-the-shortest-superstring

// version: 1; create time: 2019-10-26 14:54:25;
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


// version: 2; create time: 2020-02-16 15:57:58;
class Solution {
private:
    // Backtracking. TLE
    unordered_map<int, string> ss_mem_;
    unordered_map<int, int> c_mem_;
    string res_;

    int concat_size(const vector<string>& A, int i, int j) {
        int hashkey = (i << 4) | j;
        if (c_mem_.count(hashkey)) {
            return c_mem_[hashkey];
        }

        const int n0 = A[i].size(), n1 = A[j].size();
        int shared = 0;
        for (int size = std::min(n0, n1); size >= 1; --size) {
            auto suffix = A[i].substr(n0 - size, size);
            auto prefix = A[j].substr(0, size);
            if (suffix == prefix) {
                shared = size; break;
            }
        }
        return c_mem_[hashkey] = shared;
    }

    // Expanding. Backtracking.
    void dfs(const vector<string>& A, string cur, int used, int last, int count) {
        std::cout << cur << "\n";
        int hashkey = (used << 4) | last;
        if (ss_mem_.count(hashkey) && ss_mem_[hashkey].size() <= cur.size()) return;
        ss_mem_[hashkey] = cur;

        const int n = A.size();
        if (count == n) {
            if (res_.empty() || res_.size() > cur.size()) res_ = cur;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (used & (1 << i)) continue;
            auto shared = last >= 0 ? concat_size(A, last, i) : 0;
            dfs(A, cur + A[i].substr(shared), used | (1 << i), i, count + 1);
        }
    }

public:
    string shortestSuperstring(vector<string>& A) {
        dfs(A, "", 0, -1, 0);
        return res_;
    }
};


// version: 3; create time: 2020-02-16 16:24:42;
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
