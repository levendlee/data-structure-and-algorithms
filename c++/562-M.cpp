class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        const int nrow = M.size();
        if (nrow == 0) return 0;
        const int ncol = M[0].size();
        if (ncol == 0) return 0;

        int longest = 0;
        auto finder = [&](auto i, auto j, const auto di, const auto dj) {
            int size = 0;
            while (i >= 0 && i < nrow && j >= 0 && j < ncol) {
                size = M[i][j] == 0 ? 0 : size + 1;
                longest = std::max(longest, size);
                i += di; j += dj;
            }
        };

        for (int i = 0; i < nrow; ++i) {
            finder(i, 0, 0, 1);
            finder(i, 0, 1, 1);
            finder(i, 0, -1, 1);
            finder(i, ncol - 1, 1, -1);
            finder(i, ncol - 1, -1, -1);
        }

        for (int j = 0; j < ncol; ++j) {
            finder(0, j, 1, 0);
            finder(0, j, 1, 1);
            finder(0, j, 1, -1);
            finder(nrow - 1, j, -1, 1);
            finder(nrow - 1, j, -1, -1);
        }

        return longest;
    }
};