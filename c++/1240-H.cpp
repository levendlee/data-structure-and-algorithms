class Solution {
private:
    int m_;
    int n_;
    int min_cnt_;
    unordered_map<bitset<169>, int> mem_;

    bool all_unfilled(const bitset<169>& grid, const int si, const int sj, const int d) {
        for (int i = si; i < si + d; ++i) {
            for (int j = sj; j < sj + d; ++j) {
                if (grid[i*n_+j]) return false;
            }
        }
        return true;
    }

    void fill_all(bitset<169>& grid, const int si, const int sj, const int d, const bool v) {
        for (int i = si; i < si + d; ++i) {
            for (int j = sj; j < sj + d; ++j) {
                grid[i*n_+j] = v;
            }
        }
    }

    void dfs(bitset<169>& grid, const int fillings, const int cnt) {
        if (cnt >= min_cnt_) return;
        if (fillings == m_ * n_) {
            min_cnt_ = cnt;
            return;
        }
        if (mem_.count(grid) && mem_[grid] >= fillings) return;
        mem_[grid] = fillings;

        int fill_i, fill_j;
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (!grid[i*n_+j]) {
                    fill_i = i; fill_j = j; goto exit;
                }
            }
        }

        exit:
        for (int d = std::min(m_ - fill_i, n_ - fill_j); d >= 1; --d) {
            if (all_unfilled(grid, fill_i, fill_j, d)) {
                fill_all(grid, fill_i, fill_j, d, true);
                dfs(grid, fillings + d * d, cnt + 1);
                fill_all(grid, fill_i, fill_j, d, false);
            }
        }
    }

public:
    int tilingRectangle(int n, int m) {
        m_ = m; n_ = n; min_cnt_ = std::max(m, n);
        bitset<169> grid(0x0);
        dfs(grid, 0, 0);
        return min_cnt_;
    }
};