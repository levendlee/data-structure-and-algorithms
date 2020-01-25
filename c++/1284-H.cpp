class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        const int m = mat.size();
        if (m == 0) return -1;
        const int n = mat[0].size();
        if (n == 0) return -1;

        const bitset<9> target = 0;

        bitset<9> hash;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                hash[i*n+j] = mat[i][j];
            }
        }
        if (hash == target) return 0;

        unordered_set<bitset<9>> hashset;
        hashset.insert(hash);

        int steps = 0;
        queue<bitset<9>> bfs;
        bfs.push(hash);
        while (!bfs.empty()) {
            const int size = bfs.size();
            for (int t = 0; t < size; ++t) {
                const auto cur = bfs.front(); bfs.pop();
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        auto nex = cur;
                        constexpr int offsets[][2] = {{0,1}, {0,-1},{1,0},{-1,0}};
                        for (int k = 0; k < 4; ++k) {
                            const int ii = i + offsets[k][0];
                            const int jj = j + offsets[k][1];
                            if (ii >= 0 && ii < m && jj >= 0 && jj < n) {
                                nex[ii*n+jj] = !nex[ii*n+jj];
                            }
                        }
                        nex[i*n+j] = !nex[i*n+j];
                        if (nex == target) return steps + 1;
                        if (!hashset.count(nex)) {
                            bfs.push(nex);
                            hashset.insert(nex);
                        }
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};