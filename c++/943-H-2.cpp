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