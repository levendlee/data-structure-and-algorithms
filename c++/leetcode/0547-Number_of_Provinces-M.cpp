class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();

        vector<int> uf(n);
        iota(uf.begin(), uf.end(), 0);

        function<int(int)> find_f;
        find_f = [&](int i) {
            if (uf[i] == i) return i;
            return uf[i] = find_f(uf[i]);
        };

        auto union_f = [&](int i, int j) {
            int pi = find_f(i), pj = find_f(j);
            uf[pi] = pj;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) {
                    union_f(i, j);
                }
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            provinces += uf[i] == i;
        }
        return provinces;
    }
};
