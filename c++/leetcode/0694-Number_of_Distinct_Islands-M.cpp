// 694 Number of Distinct Islands
// https://leetcode.com/problems/number-of-distinct-islands

// version: 1; create time: 2020-01-11 11:58:37;
class Solution {
private:
    int m_;
    int n_;
    std::map<int, vector<vector<array<int, 2>>>> islands_;

public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<array<int, 2>>& island) {
        constexpr int offsets[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        grid[i][j] = 0;
        island.push_back({i, j});
        for (int k = 0; k < 4; ++k) {
            const int ii = i + offsets[k][0];
            const int jj = j + offsets[k][1];
            if (ii < 0 || ii >= m_ || jj < 0 || jj >= n_ || grid[ii][jj] == 0) continue;
            dfs(grid, ii, jj, island);
        }
    }

    bool check_unique(const vector<array<int, 2>>& island) {
        const int size = island.size();
        if (!islands_.count(size)) {
            return true;
        }
        if (size == 1) {
            return false;
        }
        for (const auto& comp : islands_[size]) {
            const int di = comp[0][0] - island[0][0];
            const int dj = comp[0][1] - island[0][1];
            bool matched = true;
            for (int k = 1; k < size; ++k) {
                if ((island[k][0] + di != comp[k][0]) ||
                    (island[k][1] + dj != comp[k][1])) {
                    matched = false;
                }
            }
            if (matched) return false;
        }
        return true;
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        const int m = grid.size(); m_ = m;
        if (m == 0) return 0;
        const int n = grid[0].size(); n_ = n;
        if (n == 0) return 0;

        int unique = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    vector<array<int, 2>> island;
                    dfs(grid, i, j, island);
                    std::sort(island.begin(), island.end());
                    if (check_unique(island)) {
                        ++unique;
                        islands_[island.size()].push_back(island);
                    }
                }
            }
        }
        /*
        for (auto& p : islands_) {
            for (auto& vec : p.second) {
                for (auto& arr : vec) {
                    std::cout << "(" << arr[0] << "," << arr[1] << "),";
                }
                std::cout << "\n";
            }
        }
        */
        return unique;
    }
};
